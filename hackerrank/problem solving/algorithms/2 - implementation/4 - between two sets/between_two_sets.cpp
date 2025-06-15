// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int lcm_array(const vector<int>& numbers);
int gcd_array(const vector<int>& numbers);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector numbers1{read_numbers(n1)};
    vector numbers2{read_numbers(n2)};

    int lcm_of_numbers1{lcm_array(numbers1)};
    int gcd_of_numbers2{gcd_array(numbers2)};

    auto rng{
        views::iota(lcm_of_numbers1, gcd_of_numbers2 + 1)
        | views::stride(lcm_of_numbers1)
        | views::filter([gcd_of_numbers2](auto i) { return gcd_of_numbers2 % i == 0; })
    };
    int count{static_cast<int>(ranges::distance(rng))};
    cout << count << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    return views::iota(0, n) | views::transform([](auto) {
        int x;
        cin >> x;
        return x;
    }) | ranges::to<vector>();
}

int lcm_array(const vector<int>& numbers)
{
    return ranges::fold_left(numbers | views::drop(1), numbers.front(), [](int a, int b) { return lcm(a, b); });
}

int gcd_array(const vector<int>& numbers)
{
    return ranges::fold_left(numbers | views::drop(1), numbers.front(), [](int a, int b) { return gcd(a, b); });
}
