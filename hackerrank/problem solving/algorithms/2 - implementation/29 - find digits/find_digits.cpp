// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;

int find_digits(int n);

int main()
{
    int n;
    cin >> n;
    for (auto x : views::iota(0, n) | views::transform([](auto) {int number; cin >> number; return find_digits(number);}))
        cout << x << '\n';

    return 0;
}

int find_digits(int n)
{
    return ranges::count_if(to_string(n), [n](auto c) {int d{c - '0'}; return d != 0 && n % d == 0;});
}
