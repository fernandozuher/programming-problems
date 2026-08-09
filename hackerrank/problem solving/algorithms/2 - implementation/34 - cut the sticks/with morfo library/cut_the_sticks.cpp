// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

vector<int> cut_the_sticks(const vector<int>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    ranges::sort(arr);
    morfo::println(cut_the_sticks(arr));
    return 0;
}

// n: length of arr
// k: number of distinct values in arr
// k <= n
// T: O(n)
//    Sorting arr beforehand is O(n log n)
// S: O(k) = O(n) extra space
//    Sorting arr beforehand is O(n) extra space
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
