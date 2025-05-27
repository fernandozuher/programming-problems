// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int birthday_cake_candles(const vector<int>& candles);

int main()
{
    int n;
    cin >> n;
    vector candles{read_numbers(n)};
    cout << birthday_cake_candles(candles);
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

int birthday_cake_candles(const vector<int>& candles)
{
    return ranges::count(candles, *ranges::max_element(candles));
}
