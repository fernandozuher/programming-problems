// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// C++23

import std;
using namespace std;

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
    vector<string> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of rows/cols of matrix
// T: O(n^2)
// S: O(1) extra space
void change_matrix_to_cavity_map(vector<string>& matrix)
{
    for (int i{ 1 }, n2 = matrix.size() - 1; i < n2; ++i)
        for (int j{ 1 }; j < n2; ++j)
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
