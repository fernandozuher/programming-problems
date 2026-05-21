// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
pair<int, int> compare_triplets(const vector<int>& triplet_a, const vector<int>& triplet_b);

int main()
{
    constexpr int n{ 3 };
    vector triplet_a{ read_numbers(n) };
    vector triplet_b{ read_numbers(n) };
    auto [score_a, score_b] {compare_triplets(triplet_a, triplet_b)};
    println("{} {}", score_a, score_b);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of a and b = 3
// T: O(3) = O(1)
// S: O(1) extra space
pair<int, int> compare_triplets(const vector<int>& triplet_a, const vector<int>& triplet_b)
{
    int score_a{}, score_b{};

    for (auto [ta, tb] : views::zip(triplet_a, triplet_b))
        if (ta > tb)
            ++score_a;
        else if (tb > ta)
            ++score_b;

    return { score_a, score_b };
}
