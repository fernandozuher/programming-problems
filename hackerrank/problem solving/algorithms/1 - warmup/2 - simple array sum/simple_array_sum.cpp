// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int simple_array_sum(const vector<int> array);

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    ranges::generate(array, [] {int n; cin >> n; return n;});
    cout << simple_array_sum(array);

    return 0;
}

    int simple_array_sum(const vector<int> array)
    {
        return accumulate(array.begin(), array.end(), 0);
    }
