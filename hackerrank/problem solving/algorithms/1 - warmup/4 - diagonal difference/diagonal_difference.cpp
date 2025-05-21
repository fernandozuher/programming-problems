// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

int diagonal_difference(int n);
vector<int> read_numbers(int n);

int main()
{
    int n;
    cin >> n;
    cout << diagonal_difference(n) << '\n';
    return 0;
}

int diagonal_difference(int n)
{
    int primary_sum{}, secondary_sum{};

    for (const auto i : views::iota(0, n)) {
        vector numbers = read_numbers(n);
        primary_sum += numbers.at(i);
        secondary_sum += numbers.at(n - i - 1);
    }

    return abs(primary_sum - secondary_sum);
}

vector<int> read_numbers(int n)
{
    return views::iota(0, n) | views::transform([](auto) {
        int x;
        cin >> x;
        return x;
    }) | ranges::to<vector>();
}
