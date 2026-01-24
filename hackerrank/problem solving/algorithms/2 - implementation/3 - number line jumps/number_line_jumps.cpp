// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// C++23

import std;
using namespace std;

tuple<int, int, int, int> read_input();
bool kangaroo(const tuple<int, int, int, int>& initial_state);

int main()
{
    auto initial_state{ read_input() };
    cout << (kangaroo(initial_state) ? "YES"s : "NO"s);
    return 0;
}

tuple<int, int, int, int> read_input()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    return { x1, v1, x2, v2 };
}

// T: O(1)
// S: O(1) extra space
bool kangaroo(const tuple<int, int, int, int>& initial_state)
{
    auto [x1, v1, x2, v2] { initial_state };

    if (v1 == v2)
        return x1 == x2;

    int distance_diff{ x2 - x1 };
    int velocity_diff{ v1 - v2 };
    return distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0;
}
