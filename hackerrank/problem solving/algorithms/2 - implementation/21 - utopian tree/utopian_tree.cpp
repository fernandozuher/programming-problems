// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> generate_heights_utopian_tree();
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    cin >> n;
    vector utopian_tree{ generate_heights_utopian_tree() };
    for (int i{}; i < n; ++i) {
        int cycles;
        cin >> cycles;
        println("{}", utopian_tree[cycles]);
    }
    return 0;
}

// k: length of output array heights = 61
// T: O(k) = O(61) = O(1). S: O(61) = O(1) extra space.
vector<int> generate_heights_utopian_tree()
{
    constexpr int max_cycles{ 60 };
    vector<int> heights(max_cycles + 1);
    for (int height{}; auto [cycle, x] : views::enumerate(heights))
        x = height += is_cycle_happening_during_spring(cycle) ? height : 1;
    return heights;
}

bool is_cycle_happening_during_spring(int cycle)
{
    return cycle & 1;
}
