// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void change_matrix_to_cavity_map(vector<string>& matrix);
    bool is_cell_cavity(const vector<string>& matrix, int i, int j);

int main()
{
    int n_rows_columns;
    cin >> n_rows_columns;

    vector<string> matrix(n_rows_columns);
    generate(matrix.begin(), matrix.end(), [] {string element; cin >> element; return element;});

    change_matrix_to_cavity_map(matrix);
    for_each(matrix.begin(), matrix.end(), [](string & element) {cout << element << '\n';});

    return 0;
}

    void change_matrix_to_cavity_map(vector<string>& matrix)
    {
        const char cavity {'X'};
        for (int i {1}, new_size {static_cast<int>(matrix.size()) - 1}; i < new_size; ++i)
            for (int j {1}; j < new_size; ++j)
                if (is_cell_cavity(matrix, i, j))
                    matrix.at(i).at(j) = {cavity};
    }

        bool is_cell_cavity(const vector<string>& matrix, int i, int j)
        {
            return matrix.at(i - 1).at(j) < matrix.at(i).at(j)
                   && matrix.at(i).at(j - 1) < matrix.at(i).at(j)
                   && matrix.at(i + 1).at(j) < matrix.at(i).at(j)
                   && matrix.at(i).at(j + 1) < matrix.at(i).at(j);
        }
