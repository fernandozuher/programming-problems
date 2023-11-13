// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> read_matrix(const int n);
int diagonal_difference(const vector<vector<int>>& matrix);

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix {read_matrix(n)};
    cout << diagonal_difference(matrix);

    return 0;
}

    vector<vector<int>> read_matrix(const int n)
    {
        vector<vector<int>> matrix(n);
        for (int i {}; i < n; ++i)
            for (int j {}; j < n; ++j) {
                int element;
                cin >> element;
                matrix.at(i).push_back(element);
            }
        return matrix;
    }

    int diagonal_difference(const vector<vector<int>>& matrix)
    {
        int primary_diagonal {}, secondary_diagonal {};

        for (int i {}, j = matrix.size() - 1, n = matrix.size(); i < n; ++i, --j) {
            primary_diagonal += matrix.at(j).at(j);
            secondary_diagonal += matrix.at(j).at(i);
        }

        return abs(primary_diagonal - secondary_diagonal);
    }
