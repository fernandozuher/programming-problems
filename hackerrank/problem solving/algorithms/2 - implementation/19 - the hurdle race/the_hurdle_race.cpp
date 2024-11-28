// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// From C++20 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read(int n);
int hurdle_race(const vector<int>& hurdles_heights, int maximum_height_can_jump);

int main()
{
    int n, maximum_height_can_jump;
    cin >> n >> maximum_height_can_jump;
    cout << hurdle_race(read(n), maximum_height_can_jump);
    return 0;
}

template <class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

int hurdle_race(const vector<int>& hurdles_heights, const int maximum_height_can_jump)
{
    return max(*ranges::max_element(hurdles_heights) - maximum_height_can_jump, 0);
}
