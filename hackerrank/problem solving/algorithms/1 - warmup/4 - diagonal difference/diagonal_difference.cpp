// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<vector<int>> read_matrix(int n);
int diagonal_difference(const vector<vector<int>>& matrix);

int main()
{
    int n;
    cin >> n;
    auto matrix {read_matrix(n)};
    cout << diagonal_difference(matrix);

    return 0;
}

    vector<vector<int>> read_matrix(const int n)
    {
        vector<vector<int>> matrix(n);
        for (auto& row : matrix)
            copy_n(istream_iterator<int>(cin), n, back_inserter(row));
        return matrix;
    }

    int diagonal_difference(const vector<vector<int>>& matrix)
    {
        int primary_diagonal{}, secondary_diagonal{};

        for (int n = matrix.size() - 1; const auto& [i, row] : matrix | views::enumerate) {
            primary_diagonal += row.at(i);
            secondary_diagonal += row.at(n--);
        }

        return abs(primary_diagonal - secondary_diagonal);
    }
