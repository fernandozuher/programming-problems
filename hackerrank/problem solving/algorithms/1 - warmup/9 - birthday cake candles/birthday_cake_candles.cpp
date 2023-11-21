// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);
int birthday_cake_candles(const vector<int>& candles);

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_int_array(n)};
    cout << birthday_cake_candles(array);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int n; cin >> n; return n;});
        return array;
    }

    int birthday_cake_candles(const vector<int>& candles)
    {
        int element_max {*ranges::max_element(candles)};
        int count_max_element = ranges::count(candles, element_max);
        return count_max_element;
    }
