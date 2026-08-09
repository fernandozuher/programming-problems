// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace views;

int min_deletions_to_equalize(const vector<int>& arr);

int main()
{
    morfo::skip_input_ln();
    vector<int> arr = morfo::readln();
    cout << min_deletions_to_equalize(arr);
    return 0;
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
int min_deletions_to_equalize(const vector<int>& arr)
{
    return arr.size() - ranges::max(values(morfo::counter<unordered_map<int, int>>(arr)));
}
