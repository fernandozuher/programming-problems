// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<long long> read_numbers(int n);
long long a_very_big_sum(const vector<long long>& arr);

int main()
{
    int n;
    cin >> n;
    vector arr{ read_numbers(n) };
    cout << a_very_big_sum(arr);
    return 0;
}

vector<long long> read_numbers(int n) {
    vector<long long> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long long a_very_big_sum(const vector<long long>& arr)
{
    return *ranges::fold_left_first(arr, plus<long long>{});
}
