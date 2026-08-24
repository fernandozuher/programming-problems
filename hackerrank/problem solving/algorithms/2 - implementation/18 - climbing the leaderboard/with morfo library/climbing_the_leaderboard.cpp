// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace ranges;

vector<int> climbing_leaderboard(const vector<int>& ranked, const vector<int>& player);

int main()
{
    morfo::skip_input_ln();
    vector<int> ranked = morfo::readln();
    morfo::unique(ranked);

    morfo::skip_input_ln();
    vector<int> player = morfo::readln();

    morfo::println(climbing_leaderboard(ranked, player));

    return 0;
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
