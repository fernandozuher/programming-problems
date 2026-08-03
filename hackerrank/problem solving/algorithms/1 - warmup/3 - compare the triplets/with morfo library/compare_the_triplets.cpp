// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C++23

import std;
import morfo;

using namespace std;

pair<int, int> compute_triplet_scores(const vector<int>& triplet_a, const vector<int>& triplet_b);

int main()
{
    constexpr int n{ 3 };
    vector<int> triplet_a = morfo::read(n);
    vector<int> triplet_b = morfo::read(n);
    auto [score_a, score_b] { compute_triplet_scores(triplet_a, triplet_b) };
    println("{} {}", score_a, score_b);
    return 0;
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
pair<int, int> compute_triplet_scores(const vector<int>& triplet_a, const vector<int>& triplet_b)
{
    int score_a{}, score_b{};

    for (auto [ta, tb] : views::zip(triplet_a, triplet_b))
        if (ta > tb)
            ++score_a;
        else if (tb > ta)
            ++score_b;

    return { score_a, score_b };
}
