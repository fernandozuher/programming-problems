// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int hurdle_race(const vector<int>& hurdles, int max_jump);

int main()
{
    int n, max_jump;
    cin >> n >> max_jump;
    vector hurdles{read_numbers(n)};
    cout << hurdle_race(hurdles, max_jump);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x : numbers)
        cin >> x;
    return numbers;
}

int hurdle_race(const vector<int>& hurdles, int max_jump)
{
    return max(0, *ranges::max_element(hurdles) - max_jump);
}
