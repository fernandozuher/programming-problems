// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int min_jumps(const vector<int>& clouds);
int skip(int idx, const vector<int>& clouds);
bool is_next_second_cloud_cumulus(int idx, const vector<int>& clouds);

int main()
{
    int n;
    cin >> n;
    cout << min_jumps(read_numbers(n));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
int min_jumps(const vector<int>& clouds)
{
    int jumps{};
    for (int i{}, size = clouds.size() - 1; i < size; i += skip(i, clouds), ++jumps);
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
