// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int min_jumps(const vector<int>& clouds);
int skip(int idx, const vector<int>& clouds);
bool is_next_second_cloud_cumulus(int idx, const vector<int>& clouds);

int main()
{
    morfo::skip_input_ln();
    vector<int> clouds = morfo::readln();
    cout << min_jumps(clouds);
    return 0;
}

// n: length of clouds
// T: O(n)
// S: O(1) extra space
int min_jumps(const vector<int>& clouds)
{
    int jumps{};
    for (int i{}, size = clouds.size() - 1; i < size; i += skip(i, clouds))
        ++jumps;
    return jumps;
}

int skip(int idx, const vector<int>& clouds)
{
    return is_next_second_cloud_cumulus(idx, clouds) ? 2 : 1;
}

bool is_next_second_cloud_cumulus(int idx, const vector<int>& clouds)
{
    return idx + 2 < clouds.size() && clouds.at(idx + 2) == 0;
}
