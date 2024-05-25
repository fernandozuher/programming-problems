// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
pair<int, int> compare_triplets(const vector<int>& array1, const vector<int>& array2);

int main()
{
    constexpr int n{3};
    vector array1 {read_int_array(n)};
    vector array2 {read_int_array(n)};
    auto [alice_score, bob_score] {compare_triplets(array1, array2)};
    cout << alice_score << ' ' << bob_score;

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array;
        copy_n(istream_iterator<int>(cin), n, back_inserter(array));
        return array;
    }

    pair<int, int> compare_triplets(const vector<int>& array1, const vector<int>& array2)
    {
        int player1{}, player2{};

        for (const auto [p1, p2] : views::zip(array1, array2))
            if (p1 > p2)
                ++player1;
            else if (p2 > p1)
                ++player2;

        return {player1, player2};
    }
