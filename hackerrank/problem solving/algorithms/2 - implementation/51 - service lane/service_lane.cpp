// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int min_width_in_segment(const vector<int>& widths, const pair<int, int>& segment);

int main()
{
    int n, t;
    cin >> n >> t;
    vector widths{ read_numbers(n) };

    for (int i{}; i < t; ++i) {
        pair<int, int> segment;
        cin >> segment.first >> segment.second;
        println("{}", min_width_in_segment(widths, segment));
    }

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array widths
// T: O(n)
// S: O(1) extra space
int min_width_in_segment(const vector<int>& widths, const pair<int, int>& segment)
{
    return *min_element(widths.begin() + segment.first, widths.begin() + segment.second + 1);
}
