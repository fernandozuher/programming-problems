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
        cout << x << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

void remove_duplicates(vector<int>& arr)
{
    auto [first, last] { ranges::unique(arr) };
    arr.erase(first, last);
}

// n: length of array player and returned output array
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player)
{
    int i = ranked.size() - 1;
    return player | views::transform([&i, &ranked](auto score) {
        while (i >= 0 && score >= ranked[i])
            --i;
        return i + 2;
        }) | ranges::to<vector>();
}
