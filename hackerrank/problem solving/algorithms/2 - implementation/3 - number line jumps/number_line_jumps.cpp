// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// C++23

#include <array>
#include <iostream>
#include <ranges>

using namespace std;

constexpr int input_size{4};

array<int, input_size> read_numbers();
bool kangaroo(const array<int, input_size>& positions_and_velocities);

int main()
{
    cout << (kangaroo(read_numbers()) ? "YES"s : "NO"s);
    return 0;
}

array<int, input_size> read_numbers()
{
    return views::iota(0, input_size) | views::transform([](auto) {
        int x;
        cin >> x;
        return x;
    }) | ranges::to<array<int, input_size> >();
}

bool kangaroo(const array<int, input_size>& positions_and_velocities)
{
    auto [x1, v1, x2, v2]{positions_and_velocities};

    if (v1 == v2)
        return x1 == x2;

    int distance_diff{x2 - x1};
    int velocity_diff{v1 - v2};
    return distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0;
}
