// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (auto [i, word] = tuple{0, ""s}; i < n && cin >> word; ++i) {
        string word1, word2;

        for (bool is_word1_turn {true}; const auto& ch : word) {
            is_word1_turn ? word1 += ch : word2 += ch;
            is_word1_turn = !is_word1_turn;
        }

        cout << word1 << ' ' << word2 << '\n';
    }

    return 0;
}
