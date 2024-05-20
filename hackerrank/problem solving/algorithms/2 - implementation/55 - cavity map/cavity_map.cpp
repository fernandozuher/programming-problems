// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;
using namespace views;

void change_matrix_to_cavity_map_in_place(vector<string>& matrix);
    bool is_cell_cavity(const vector<string>& matrix, unsigned i, unsigned j);

int main()
{
    int n_rows_columns;
    cin >> n_rows_columns;
    vector<string> matrix(n_rows_columns);
    ranges::generate(matrix, [] {string x; cin >> x; return x;});
    change_matrix_to_cavity_map_in_place(matrix);
    ranges::for_each(matrix, [](const auto& x) {cout << x << '\n';});

    return 0;
}

    void change_matrix_to_cavity_map_in_place(vector<string>& matrix)
    {
        if (constexpr auto min_input_to_look_for_cavity {3}; matrix.size() < min_input_to_look_for_cavity)
            return;

        constexpr auto start_end_from_row_column {1u};
        const auto range {iota(start_end_from_row_column, matrix.size() - start_end_from_row_column)};
        for (constexpr char cavity {'X'}; const auto i : range)
            for (const auto j : range)
                if (is_cell_cavity(matrix, i, j))
                    matrix.at(i).at(j) = cavity;
    }

        bool is_cell_cavity(const vector<string>& matrix, const unsigned i, const unsigned j)
        {
            return matrix.at(i - 1).at(j) < matrix.at(i).at(j)
                   && matrix.at(i).at(j - 1) < matrix.at(i).at(j)
                   && matrix.at(i + 1).at(j) < matrix.at(i).at(j)
                   && matrix.at(i).at(j + 1) < matrix.at(i).at(j);
        }
