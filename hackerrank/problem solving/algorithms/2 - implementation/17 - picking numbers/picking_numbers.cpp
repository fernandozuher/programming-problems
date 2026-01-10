// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C++23

import std;
using namespace std;

unordered_map<int, int> counter(int n);
int picking_numbers(const unordered_map<int, int>& frequency);

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << picking_numbers(counter(n));
    return 0;
}

unordered_map<int, int> counter(int n)
{
    unordered_map<int, int> frequency;
    for (int i{}, num; i < n && cin >> num; ++i)
        ++frequency[num];
    return frequency;
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
int picking_numbers(const unordered_map<int, int>& frequency)
{
    int max_len{};
    for (auto [num, _] : frequency) {
        int current{ frequency.at(num) + (frequency.contains(num + 1) ? frequency.at(num + 1) : 0) };
        max_len = max(max_len, current);
    }
    return max_len;
}
