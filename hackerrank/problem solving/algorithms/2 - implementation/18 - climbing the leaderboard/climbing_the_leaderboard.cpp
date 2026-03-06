// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
void remove_duplicates(vector<int>& arr);
vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player);

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector ranked{ read_numbers(n) };
    remove_duplicates(ranked);
    cin >> n;
    vector player{ read_numbers(n) };

    for (auto x : climbing_leaderboard(ranked, player))
        println("{}", x);

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(1) extra space
void remove_duplicates(vector<int>& arr)
{
    auto [first, last] { ranges::unique(arr) };
    arr.erase(first, last);
}

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player)
{
    int i = ranked.size() - 1;
    return player | views::transform([&i, &ranked](auto score) {
        while (i >= 0 && score >= ranked[i])
            --i;
        return i + 2;
        }) |
        ranges::to<vector>();
}
