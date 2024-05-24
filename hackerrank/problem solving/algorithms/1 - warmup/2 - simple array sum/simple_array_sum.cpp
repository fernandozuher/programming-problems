// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int simple_array_sum(const vector<int>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array;
    copy_n(istream_iterator<int>(cin), n, back_inserter(array));
    cout << simple_array_sum(array);

    return 0;
}

    int simple_array_sum(const vector<int>& array)
    {
        return *ranges::fold_left_first(array, plus());
    }
