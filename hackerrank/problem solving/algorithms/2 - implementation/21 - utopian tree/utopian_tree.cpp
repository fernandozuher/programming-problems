// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read(int n);
vector<int> calculate_tree_heights(const vector<int>& test_cases);
int calculate_height(int cycles);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    cin >> n;
    vector<int> test_cases{read(n)};
    ranges::copy(calculate_tree_heights(test_cases), ostream_iterator<int>(cout, "\n"));
    return 0;
}

template <class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

vector<int> calculate_tree_heights(const vector<int>& test_cases)
{
    return test_cases | views::transform(calculate_height) | ranges::to<vector<int>>();
}

int calculate_height(const int cycles)
{
    int height{1};
    for (const int cycle : views::iota(1, cycles + 1))
        height = is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
    return height;
}

bool is_cycle_happening_during_spring(const int cycle)
{
    return cycle & 1;
}
