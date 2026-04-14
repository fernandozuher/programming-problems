// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// C++23

import std;
using namespace std;
using namespace ranges;

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
    return views::iota(0, n) | views::transform([](auto) {int x; cin >> x; return x; }) | to<vector>();
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
int min_width_in_segment(const vector<int>& widths, const pair<int, int>& segment)
{
    int start{ segment.first }, finish{ segment.second };
    return *ranges::min_element(widths.begin() + start, widths.begin() + finish + 1);
}
