// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
void remove_duplicates(vector<int>& numbers);
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
    ranges::copy(climbing_leaderboard(ranked, player), ostream_iterator<int>(cout, "\n"));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x: numbers)
        cin >> x;
    return numbers;
}

void remove_duplicates(vector<int>& numbers)
{
    auto [first, last]{ranges::unique(numbers)};
    numbers.erase(first, last);
}

vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player)
{
    int i = ranked.size() - 1;
    return player | views::transform([&i, &ranked](auto score) {
        while (i >= 0 && score >= ranked[i])
            --i;
        return i + 2;
    }) | ranges::to<vector>();
}
