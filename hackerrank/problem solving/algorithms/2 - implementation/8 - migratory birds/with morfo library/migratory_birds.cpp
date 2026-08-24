// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

unordered_map<int, int> read_input();
int find_most_spotted_bird(const unordered_map<int, int>& birds_to_counts);

int main()
{
    auto birds_to_counts{ read_input() };
    cout << find_most_spotted_bird(birds_to_counts);
    return 0;
}

// n: length of input
// T: O(n)
// S: O(n) extra space
unordered_map<int, int> read_input()
{
    morfo::skip_input_ln();
    return morfo::counter<unordered_map<int, int>>(morfo::readln<int>());
}

// n: length of birds_to_counts
// T: O(n)
// S: O(1) extra space
int find_most_spotted_bird(const unordered_map<int, int>& birds_to_counts)
{
    auto [id, count] { *ranges::max_element(birds_to_counts, {}, [](const auto& x) { return pair<int, int>(x.second, -x.first); }) };
    return id;
}
