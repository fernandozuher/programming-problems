// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int hurdle_race(const vector<int>& hurdles, int max_jump);

int main()
{
    morfo::skip_input();
    int max_jump = morfo::read();
    vector<int> hurdles = morfo::readln();
    cout << hurdle_race(hurdles, max_jump);
    return 0;
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int hurdle_race(const vector<int>& hurdles, int max_jump)
{
    return max(0, ranges::max(hurdles) - max_jump);
}
