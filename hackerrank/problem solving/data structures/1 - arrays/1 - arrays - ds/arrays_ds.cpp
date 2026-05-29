// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;

    ranges::reverse(arr);
    for (auto x : arr)
        print("{} ", x);

    return 0;
}
