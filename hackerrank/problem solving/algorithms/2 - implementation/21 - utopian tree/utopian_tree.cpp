// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
vector<int> calculate_tree_heights(const vector<int>& test_cases);
int calculate_height(int cycles);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    cin >> n;
    for (auto x : calculate_tree_heights(read_numbers(n)))
        cout << x << '\n';
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x: numbers)
        cin >> x;
    return numbers;
}

vector<int> calculate_tree_heights(const vector<int>& test_cases)
{
    return test_cases | views::transform(calculate_height) | ranges::to<vector<int>>();
}

int calculate_height(int cycles)
{
    return ranges::fold_left(views::iota(1, cycles + 1), 1, [](auto height, auto cycle) {
        return is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
    });
}

bool is_cycle_happening_during_spring(int cycle)
{
    return cycle & 1;
}
