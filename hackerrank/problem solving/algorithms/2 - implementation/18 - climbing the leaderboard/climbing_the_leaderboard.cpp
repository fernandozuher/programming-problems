// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
void remove_duplicates(vector<int>& arr);
vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player);

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector ranked{read_numbers(n)};
    remove_duplicates(ranked);
    cin >> n;
    vector player{read_numbers(n)};
    for (auto x : climbing_leaderboard(ranked, player))
        cout << x << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x: arr)
        cin >> x;
    return arr;
}

void remove_duplicates(vector<int>& arr)
{
    auto [first, last]{ranges::unique(arr)};
    arr.erase(first, last);
}

vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player)
{
    vector<int> playerRanks(player.size());
    int i = ranked.size() - 1;

    for (auto [j, x] : views::enumerate(player)) {
        while (i >= 0 && x >= ranked[i])
            --i;
        playerRanks[j] = i + 2;
    }

    return playerRanks;
}
