// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int between_two_sets(const vector<int>& a, const vector<int>& b);
int lcm_array(const vector<int>& numbers);
int gcd_array(const vector<int>& numbers);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector numbers_a{read_numbers(n1)};
    vector numbers_b{read_numbers(n2)};
    cout << between_two_sets(numbers_a, numbers_b) << '\n';
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

int between_two_sets(const vector<int>& a, const vector<int>& b)
{
    int lcm_of_a{lcm_array(a)};
    int gcd_of_b{gcd_array(b)};

    auto rng{
        views::iota(lcm_of_a, gcd_of_b + 1)
        | views::stride(lcm_of_a)
        | views::filter([gcd_of_b](auto i) { return gcd_of_b % i == 0; })
    };
    return static_cast<int>(ranges::distance(rng));
}

int lcm_array(const vector<int>& numbers)
{
    return ranges::fold_left(numbers | views::drop(1), numbers.front(), [](int a, int b) { return lcm(a, b); });
}

int gcd_array(const vector<int>& numbers)
{
    return ranges::fold_left(numbers | views::drop(1), numbers.front(), [](int a, int b) { return gcd(a, b); });
}
