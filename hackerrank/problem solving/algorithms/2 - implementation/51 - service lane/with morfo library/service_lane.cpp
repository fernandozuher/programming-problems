// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace ranges;

int min_width_in_segment(const vector<int>& widths, const pair<int, int>& segment);

int main()
{
    auto [n, t] = morfo::read<int, int>();
    vector<int> widths = morfo::read(n);

    for (int i{}; i < t; ++i) {
        auto [entry, exit] = morfo::read<int, int>();
        println("{}", min_width_in_segment(widths, { entry, exit }));
    }

    return 0;
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
int min_width_in_segment(const vector<int>& widths, const pair<int, int>& segment)
{
    int start{ segment.first }, finish{ segment.second };
    return *ranges::min_element(widths.begin() + start, widths.begin() + finish + 1);
}
