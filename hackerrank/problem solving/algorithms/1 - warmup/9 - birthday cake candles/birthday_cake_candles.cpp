// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
int birthday_cake_candles(const vector<int>& candles);

int main()
{
    int n;
    cin >> n;
    vector array {read_int_array(n)};
    cout << birthday_cake_candles(array);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array;
        copy_n(istream_iterator<int>(cin), n, back_inserter(array));
        return array;
    }

    int birthday_cake_candles(const vector<int>& candles)
    {
        return ranges::count(candles, *ranges::max_element(candles));
    }
