// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int birthday_cake_candles(const vector<int>& candles);

int main()
{
    morfo::skip_input_ln();
    vector<int> candles = morfo::readln();
    cout << birthday_cake_candles(candles);
    return 0;
}

// n: length of candles
// T: O(2n) => O(n)
// S: O(1) extra space
int birthday_cake_candles(const vector<int>& candles)
{
    return ranges::count(candles, ranges::max(candles));
}
