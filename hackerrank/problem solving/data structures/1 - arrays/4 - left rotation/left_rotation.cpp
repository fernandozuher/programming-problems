// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, rotate_by;
    cin >> n >> rotate_by;
    vector<int> array(n);
    ranges::generate(array, [] {int x; cin >> x; return x;});

    if (rotate_by > n - 1)
        rotate_by %= n;

    rotate(array.begin(), array.begin() + rotate_by, array.end());

    for (const auto x : array)
        cout << x << ' ';

    return 0;
}
