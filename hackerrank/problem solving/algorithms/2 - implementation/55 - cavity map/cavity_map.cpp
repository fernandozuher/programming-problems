// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// C++23

import std;
using namespace std;
using namespace ranges;

vector<string> read_matrix(int n);
void change_matrix_to_cavity_map(vector<string>& matrix);
bool is_cell_cavity(const vector<string>& matrix, int i, int j);

int main()
{
    int n;
    cin >> n;
    vector matrix{ read_matrix(n) };
    change_matrix_to_cavity_map(matrix);
    for (const auto& x : matrix)
        println("{}", x);

    return 0;
}

vector<string> read_matrix(int n)
{
    return views::iota(0, n) | views::transform([](auto) { string x; cin >> x; return x; }) | to<vector>();
}

// n: length of matrix' rows
// T: O(n^2)
// S: O(1) extra space
void change_matrix_to_cavity_map(vector<string>& matrix)
{
    for (int i{ 1 }, n = matrix.size() - 1; i < n; ++i)
        for (int j{ 1 }; j < n; ++j)
            if (is_cell_cavity(matrix, i, j))
                matrix.at(i).at(j) = 'X';
}

bool is_cell_cavity(const vector<string>& matrix, int i, int j)
{
    char c{ matrix[i][j] };
    return matrix.at(i - 1).at(j) < c &&
        matrix.at(i).at(j - 1) < c &&
        matrix.at(i + 1).at(j) < c &&
        matrix.at(i).at(j + 1) < c;
}
