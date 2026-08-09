// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace ranges;

void remove_duplicates(vector<int>& arr);
vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player);

int main()
{
    morfo::skip_input_ln();
    vector<int> ranked = morfo::readln();
    remove_duplicates(ranked);

    morfo::skip_input_ln();
    vector<int> player = morfo::readln();

    morfo::println(climbing_leaderboard(ranked, player));

    return 0;
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
    return player |

        views::transform([&i, &ranked](auto score) {
        while (i >= 0 && score >= ranked[i])
            --i;
        return i + 2;
            }) |

        to<vector>();
}
