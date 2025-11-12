// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;

int utopian_tree(int cycles);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    cin >> n;
    for (int i{}; i < n; ++i) {
        int cycles;
        cin >> cycles;
        cout << utopian_tree(cycles) << '\n';
    }
    return 0;
}

int utopian_tree(int cycles)
{
    return ranges::fold_left(views::iota(1, cycles + 1), 1, [](auto height, auto cycle) {
        return is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
    });
}

bool is_cycle_happening_during_spring(int cycle)
{
    return cycle & 1;
}
