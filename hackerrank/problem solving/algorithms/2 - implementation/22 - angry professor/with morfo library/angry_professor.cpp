// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

bool angry_professor(const vector<int>& arrival_times, int threshold);

int main()
{
    int n = morfo::read();

    for (int i{}; i < n; ++i) {
        morfo::skip_input();
        int threshold = morfo::read();
        vector<int> arrival_times = morfo::readln();
        puts(angry_professor(arrival_times, threshold) ? "YES" : "NO");
    }

    return 0;
}

// k: length of arrival_times
// T: O(k)
// S: O(1) extra space
bool angry_professor(const vector<int>& arrival_times, int threshold)
{
    int on_time = ranges::count_if(arrival_times, [](auto t) { return t <= 0; });
    return on_time < threshold;
}
