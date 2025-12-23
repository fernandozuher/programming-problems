// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(unsigned n);
int min_width_in_segment(const vector<int>& width_measurements, const pair<int, int>& segment);

// n: len array widths
// t: number test cases
// k_i: len of i-th queried segment = segment.second - segment.first + 1
// avg_k: avg len segments over all test cases

// T:
  // Total: O(n + E k_i) = O(n + t * avg_k)
  // Worst-case: O(n + t * n) = O(t * n)
// S: O(n)
int main()
{
    unsigned n, t;
    cin >> n >> t;
    vector widths{ read_numbers(n) };

    while (t--) {
        pair<int, int> segment;
        cin >> segment.first >> segment.second;
        println("{}", min_width_in_segment(widths, segment));
    }

    return 0;
}

// n: len arr
// T O(n), S O(n)
vector<int> read_numbers(unsigned n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// k: len segment = segment.second - segment.first + 1
// T O(k), S O(1)
int min_width_in_segment(const vector<int>& width_measurements, const pair<int, int>& segment)
{
    return *min_element(width_measurements.begin() + segment.first, width_measurements.begin() + segment.second + 1);
}
