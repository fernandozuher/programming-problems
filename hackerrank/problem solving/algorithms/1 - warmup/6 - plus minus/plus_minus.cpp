// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C++23

#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
array<double, 3> plus_minus(const vector<int>& numbers);
void print_ratios(const array<double, 3>& ratios);

int main()
{
    int n;
    cin >> n;
    vector numbers{read_numbers(n)};
    auto ratios{plus_minus(numbers)};
    print_ratios(ratios);
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

array<double, 3> plus_minus(const vector<int>& numbers)
{
    int positive{}, negative{}, zero{};

    for (auto x : numbers)
        if (x > 0)
            ++positive;
        else if (x < 0)
            ++negative;
        else
            ++zero;

    double n{static_cast<double>(numbers.size())};
    return {positive / n, negative / n, zero / n};
}

void print_ratios(const array<double, 3>& ratios)
{
    cout << fixed << setprecision(6);
    for (auto ratio : ratios)
        cout << ratio << '\n';
}
