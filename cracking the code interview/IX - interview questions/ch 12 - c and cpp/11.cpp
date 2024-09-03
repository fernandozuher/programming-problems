// From C++20

#include <iostream>
#include <ranges>

using namespace std;

template<class T = int>
T** my_2d_a1loc(int n_rows, int n_cols);

template<class T = int>
T** free_matrix(T** matrix);

int main()
{
    constexpr int r{3}, c{3};
    int** matrix = my_2d_a1loc(r, c);

    for (int i{}; i < r; ++i)
        for (int j{}; j < c; ++j)
            matrix[i][j] = i + j;

    for (int i{}; i < r; ++i) {
        for (int j{}; j < c; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    matrix = free_matrix(matrix);
    return 0;
}

template<class T>
T** my_2d_a1loc(const int n_rows, const int n_cols)
{
    auto matrix_2d = static_cast<T**>(malloc(sizeof(T*) * n_rows));
    auto matrix_1d = static_cast<T*>(malloc(sizeof(T) * n_rows * n_cols));
    for (const int i : views::iota(0, n_rows))
        matrix_2d[i] = &matrix_1d[i * n_cols];
    return matrix_2d;
}

template<class T>
T** free_matrix(T** matrix)
{
    if (matrix) {
        free(matrix[0]);
        free(matrix);
    }
    return nullptr;
}
