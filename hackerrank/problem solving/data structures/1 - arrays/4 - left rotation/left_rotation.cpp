// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
void rotate(vector<int>& arr, int rotate_by);

int main()
{
    int n, rotate_by;
    cin >> n >> rotate_by;
    vector arr{ read_numbers(n) };

    rotate(arr, rotate_by);
    for (auto x : arr)
        print("{} ", x);

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void rotate(vector<int>& arr, int rotate_by)
{
    if (rotate_by >= arr.size())
        rotate_by %= arr.size();
    rotate(arr.begin(), arr.begin() + rotate_by, arr.end());
}
