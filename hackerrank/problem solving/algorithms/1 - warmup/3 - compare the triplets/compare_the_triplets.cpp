// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_nums(size_t n);
pair<int, int> count_scores_between(const vector<int>& triplet_a, const vector<int>& triplet_b);

int main()
{
    constexpr int n{ 3 };
    vector triplet_a{ read_nums(n) };
    vector triplet_b{ read_nums(n) };
    auto [score_a, score_b] {count_scores_between(triplet_a, triplet_b)};
    println("{} {}", score_a, score_b);
    return 0;
}

vector<int> read_nums(size_t n)
{
    return views::iota(0ull, n)
        | views::transform([](auto) {int x; cin >> x; return x;})
        | ranges::to<vector>();
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
pair<int, int> count_scores_between(const vector<int>& triplet_a, const vector<int>& triplet_b)
{
    int score_a{}, score_b{};

    for (auto [ta, tb] : views::zip(triplet_a, triplet_b))
        if (ta > tb)
            ++score_a;
        else if (tb > ta)
            ++score_b;

    return { score_a, score_b };
}
