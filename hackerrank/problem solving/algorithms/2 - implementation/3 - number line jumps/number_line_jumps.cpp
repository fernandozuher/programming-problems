// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
bool kangaroo(const vector<int>& positions_and_velocities);

int main()
{
    constexpr int input_size{ 4 };
    cout << (kangaroo(read_numbers(input_size)) ? "YES"s : "NO"s);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

bool kangaroo(const vector<int>& positions_and_velocities)
{
    int x1{positions_and_velocities[0]};
    int v1{positions_and_velocities[1]};
    int x2{positions_and_velocities[2]};
    int v2{positions_and_velocities[3]};

    if (v1 == v2)
        return x1 == x2;

    int distance_diff{ x2 - x1 };
    int velocity_diff{ v1 - v2 };
    return distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0;
}
