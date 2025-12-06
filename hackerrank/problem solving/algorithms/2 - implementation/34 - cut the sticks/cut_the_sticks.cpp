// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
vector<int> cut_the_sticks(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    vector<int> arr{ read_numbers(n) };
    ranges::sort(arr);
    for (auto x : cut_the_sticks(arr))
        cout << x << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

vector<int> cut_the_sticks(const vector<int>& arr)
{
    vector<int> res;
    for (int i{}, n = arr.size(); i < n;) {
        res.push_back(n - i);
        for (const int shortest{ arr[i] }; i < n && arr[i] == shortest; ++i);
    }
    return res;
}
