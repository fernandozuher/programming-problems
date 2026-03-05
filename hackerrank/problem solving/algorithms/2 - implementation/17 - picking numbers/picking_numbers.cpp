// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C++23

import std;
using namespace std;

unordered_map<int, int> counter(int n);
int picking_numbers(const unordered_map<int, int>& freq_map);

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << picking_numbers(counter(n));
    return 0;
}

// n: length of initial input array of numbers
// k: length of freq_map
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
unordered_map<int, int> counter(int n)
{
    unordered_map<int, int> freq_map;
    for (int i{}; i < n; ++i) {
        int num;
        cin >> num;
        ++freq_map[num];
    }
    return freq_map;
}

// k: length of freq_map
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int picking_numbers(const unordered_map<int, int>& freq_map)
{
    int max_len{};
    for (auto [num, _] : freq_map) {
        int current{ freq_map.at(num) + (freq_map.contains(num + 1) ? freq_map.at(num + 1) : 0) };
        max_len = max(max_len, current);
    }
    return max_len;
}
