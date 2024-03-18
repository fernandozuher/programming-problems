// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int max_hourglass_sum(const vector<vector<int>>& matrix);
    int hourglass_sum(const vector<vector<int>>& matrix, const pair<int, int>& index);

int main()
{
    constexpr int n {6};
    vector<vector<int>> matrix(n, vector<int>(n));
    for (auto& row : matrix)
        ranges::generate(row, [] {int x; cin >> x; return x;});

    cout << max_hourglass_sum(matrix);

    return 0;
}

    int max_hourglass_sum(const vector<vector<int>>& matrix)
    {
        int max_sum {numeric_limits<int>::min()};

        for (const auto rows_cols = {1, 2, 3, 4}; const int i : rows_cols)
            for (int j : rows_cols) {
                int current_sum {hourglass_sum(matrix, {i, j})};
                max_sum = max(max_sum, current_sum);
            }

        return max_sum;
    }

        int hourglass_sum(const vector<vector<int>>& matrix, const pair<int, int>& index)
        {
            int i {index.first};
            int j {index.second};
            return matrix.at(i - 1).at(j - 1) + matrix.at(i - 1).at(j) + matrix.at(i - 1).at(j + 1)
                   + matrix.at(i).at(j) +
                   matrix.at(i + 1).at(j - 1) + matrix.at(i + 1).at(j) + matrix.at(i + 1).at(j + 1);
        }
