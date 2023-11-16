// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long a_very_big_sum(const vector<int>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    ranges::generate(array, [] {int n; cin >> n; return n;});
    cout << a_very_big_sum(array);

    return 0;
}

    long a_very_big_sum(const vector<int>& array)
    {
        return accumulate(array.begin(), array.end(), 0L);
    }
