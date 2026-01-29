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
        println("{}", x);
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
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
vector<int> cut_the_sticks(const vector<int>& arr)
{
    vector<int> res;
    int slow{}, n = arr.size();

    for (int fast{}; fast < n; ++fast) {
        if (arr[slow] == arr[fast])
            continue;
        res.push_back(n - slow);
        slow = fast;
    }

    res.push_back(n - slow);
    return res;
}
