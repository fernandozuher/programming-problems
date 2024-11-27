// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read(int n);
template <class T = int>
vector<T> read_without_duplicates(int n);

vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player);
int binary_search_descending_order(const vector<int>& array, int low, int high, int key);

int main()
{
    int n;
    cin >> n;
    vector ranked{read_without_duplicates(n)};
    cin >> n;
    vector player{read(n)};
    ranges::copy(climbing_leaderboard(ranked, player), ostream_iterator<int>(cout, "\n"));
    return 0;
}

template <class T>
vector<T> read_without_duplicates(int n)
{
    auto array{read(n)};
    auto [first, last]{ranges::unique(array)};
    array.erase(first, last);
    return array;
}

template <class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player)
{
    vector<int> player_rank(player.size());
    const int last_index{static_cast<int>(ranked.size() - 1)};
    for (auto [rank, player_x] : views::zip(player_rank, player))
        rank = binary_search_descending_order(ranked, 0, last_index, player_x) + 1;
    return player_rank;
}

int binary_search_descending_order(const vector<int>& array, int low, int high, const int key)
{
    while (high >= low) {
        int middle{(low + high) / 2};
        if (key == array.at(middle))
            return middle;
        if (key > array.at(middle))
            high = middle - 1;
        else
            low = middle + 1;
    }
    return low;
}
