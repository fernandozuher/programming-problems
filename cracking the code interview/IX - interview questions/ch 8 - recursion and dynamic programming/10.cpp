// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <set>
#include <vector>

using namespace std;

struct Surround {
    pair<int, int> up{-1, -1}, down{-1, -1};
    pair<int, int> left{-1, -1}, right{-1, -1};

    Surround(const pair<int, int>& point, const int rows, const int cols)
    {
        const auto [i, j]{point};
        if (i - 1 >= 0)
            up = {i - 1, j};
        if (i + 1 < rows)
            down = {i + 1, j};

        if (j - 1 >= 0)
            left = {i, j - 1};
        if (j + 1 < cols)
            right = {i, j + 1};
    }
};

vector<vector<char>> generate_matrix(int rows, int cols);
void print_matrix(const vector<vector<char>>& matrix);
void paint_fill(vector<vector<char>>& matrix, const pair<int, int>& point, char new_color);
void paint_fill(vector<vector<char>>& matrix, const pair<int, int>& point, char new_color, char original_color,
                set<pair<int, int>>& visited);

int main()
{
    constexpr int rows{10}, cols{10};
    auto matrix{generate_matrix(rows, cols)};
    print_matrix(matrix);
    println("");

    constexpr pair point{rows / 2, cols / 2};
    constexpr char new_color = 'o';
    paint_fill(matrix, point, new_color);
    print_matrix(matrix);

    return 0;
}

vector<vector<char>> generate_matrix(const int rows, const int cols)
{
    vector matrix(rows, vector(cols, '-'));
    const pair middle_point{rows / 2, cols / 2};

    matrix.front().front() = 'x';
    ranges::fill(matrix.at(middle_point.first), 'x');
    matrix.back().back() = 'x';

    matrix.at(middle_point.first - 1).at(middle_point.second) = 'x';
    matrix.at(middle_point.first + 1).at(middle_point.second) = 'x';

    return matrix;
}

void print_matrix(const vector<vector<char>>& matrix)
{
    for (const auto& row : matrix) {
        ranges::copy(row, ostream_iterator<char>(cout, " "));
        println("");
    }
}

void paint_fill(vector<vector<char>>& matrix, const pair<int, int>& point, const char new_color)
{
    if (point.first < 0 || point.second < 0)
        throw out_of_range("Point index can't be negative");
    if (point.first >= matrix.size() || point.second >= matrix.front().size())
        throw out_of_range("Point index are beyond the range of the matrix");

    const char original_color{matrix.at(point.first).at(point.second)};
    set<pair<int, int>> visited;
    paint_fill(matrix, point, new_color, original_color, visited);
}

void paint_fill(vector<vector<char>>& matrix, const pair<int, int>& point, const char new_color,
                const char original_color, set<pair<int, int>>& visited)
{
    if (matrix.at(point.first).at(point.second) != original_color)
        return;

    matrix.at(point.first).at(point.second) = new_color;

    Surround surround(point, matrix.size(), matrix.front().size());
    const auto around = {surround.left, surround.right, surround.up, surround.down};
    for (const auto& p : around)
        if (p != pair{-1, -1} && !visited.contains(p)) {
            visited.insert(p);
            paint_fill(matrix, p, new_color, original_color, visited);
        }
}
