// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;
using namespace views;

int find_beautiful_triplets(const vector<int>& array, int beautiful_difference);

int main()
{
    int n, beautiful_difference;
    cin >> n >> beautiful_difference;
    vector<int> array(n);

    auto read {[] {int x; cin >> x; return x;}};
    ranges::generate(array, read);

    cout << find_beautiful_triplets(array, beautiful_difference) << '\n';

    return 0;
}

    int find_beautiful_triplets(const vector<int>& array, const int beautiful_difference)
    {
        int n_beautiful_triplets{};

        if (const int n {static_cast<int>(array.size())}; n > 2)
            for (const auto [i, v1] : array | take(n - 2) | enumerate)
                for (const auto [j, v2] : array | drop(i + 1) | take(n - 1) | enumerate) {

                    if (const int first_difference {v2 - v1}; first_difference < beautiful_difference)
                        continue;
                    else if (first_difference > beautiful_difference)
                        break;

                    for (const int v3 : array | drop(j + i + 2))
                        if (const int second_difference {v3 - v2}; second_difference == beautiful_difference)
                            ++n_beautiful_triplets;
                        else if (second_difference > beautiful_difference)
                            break;
                }

        return n_beautiful_triplets;
    }
