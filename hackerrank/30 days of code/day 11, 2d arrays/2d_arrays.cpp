// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<vector<int>> read_matrix();
int calculate_max_sum(const vector<vector<int>>& matrix);
    int sum_around(const vector<vector<int>>& matrix, const int i, const int j);

int main()
{
    vector<vector<int>> matrix {read_matrix()};
    int max_sum {calculate_max_sum(matrix)};
    cout << max_sum;

    return 0;
}

    vector<vector<int>> read_matrix()
    {
        constexpr int n_rows_columns {6};
        vector<vector<int>> matrix(n_rows_columns, vector<int>(n_rows_columns));

        for (auto& row : matrix)
            ranges::generate(row, [] {int n; cin >> n; return n;});

        return matrix;
    }

    int calculate_max_sum(const vector<vector<int>>& matrix)
    {
        int max_sum {INT_MIN};

        for (int i {1}, before_rows_columns_limit {5}; i < before_rows_columns_limit; ++i)
            for (int j {1}; j < before_rows_columns_limit; ++j)
                max_sum = max(max_sum, sum_around(matrix, i, j));

        return max_sum;
    }

        int sum_around(const vector<vector<int>>& matrix, const int i, const int j)
        {
            return matrix.at(i - 1).at(j - 1) + matrix.at(i - 1).at(j) + matrix.at(i - 1).at(j + 1)
                   + matrix.at(i).at(j)
                   + matrix.at(i + 1).at(j - 1) + matrix.at(i + 1).at(j) + matrix.at(i + 1).at(j + 1);
        }
