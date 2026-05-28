// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int birthday_cake_candles(const vector<int>& candles);

int main()
{
    int n;
    cin >> n;
    vector candles{ read_numbers(n) };
    cout << birthday_cake_candles(candles);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
int birthday_cake_candles(const vector<int>& candles)
{
    return ranges::count(candles, ranges::max(candles));
}
