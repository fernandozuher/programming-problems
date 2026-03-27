// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// C++23

import std;
using namespace std;
using namespace views;

vector<int> read_numbers(int n);
int min_deletions_to_equalize(const vector<int>& arr);
unordered_map<int, int> counter(const vector<int>& arr);

int main()
{
    int n;
    cin >> n;
    cout << min_deletions_to_equalize(read_numbers(n));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
int min_deletions_to_equalize(const vector<int>& arr)
{
    return arr.size() - ranges::max(values(counter(arr)));
}

unordered_map<int, int> counter(const vector<int>& arr)
{
    unordered_map<int, int> freq_map;
    for (auto x : arr)
        ++freq_map[x];
    return freq_map;
}
