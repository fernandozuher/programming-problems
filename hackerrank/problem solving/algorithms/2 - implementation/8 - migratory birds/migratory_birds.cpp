// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// C++23

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
    int n;
    cin >> n;
    unordered_map<int, int> freq_map;

    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        ++freq_map[x];
    }

    return freq_map;
}

// n: length of birds_to_counts
// T: O(n)
// S: O(1) extra space
int find_most_spotted_bird(const unordered_map<int, int>& birds_to_counts)
{
    auto [id, count] { *ranges::max_element(birds_to_counts, {}, [](const auto& x) { return pair<int, int>(x.second, -x.first); }) };
    return id;
}
