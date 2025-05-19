// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>

using namespace std;

constexpr int triplet_size{3};

array<int, triplet_size> read_input();
pair<int, int> compare_triplets(const array<int, triplet_size>& triplet_a, const array<int, triplet_size>& triplet_b);

int main()
{
    array triplet_a{read_input()};
    array triplet_b{read_input()};
    auto [score_a, score_b]{compare_triplets(triplet_a, triplet_b)};
    cout << score_a << ' ' << score_b << '\n';
    return 0;
}

array<int, triplet_size> read_input()
{
    array<int, triplet_size> result;
    for (auto& x : result)
        cin >> x;
    return result;
}

pair<int, int> compare_triplets(const array<int, triplet_size>& triplet_a, const array<int, triplet_size>& triplet_b)
{
    int score_a{}, score_b{};

    for (auto [ta, tb] : views::zip(triplet_a, triplet_b))
        if (ta > tb)
            ++score_a;
        else if (tb > ta)
            ++score_b;

    return {score_a, score_b};
}
