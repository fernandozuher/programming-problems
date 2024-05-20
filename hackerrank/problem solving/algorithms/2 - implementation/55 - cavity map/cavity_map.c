// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// From C23

#include <stdio.h>

void read_square_matrix_in_place(int n, int m, char matrix[n][m]);
void change_matrix_to_cavity_map(int n, int m, char matrix[n][m]);
    bool is_cell_cavity(int n, int m, const char matrix[n][m], int i, int j);

int main()
{
    int n_rows;
    scanf("%d", &n_rows);

    const int terminator = 1;
    int n_cols = n_rows + terminator;
    char matrix[n_rows][n_cols];
    read_square_matrix_in_place(n_rows, n_cols, matrix);

    change_matrix_to_cavity_map(n_rows, n_cols, matrix);
    for (int i = 0; i < n_rows; ++i)
        printf("%s\n", matrix[i]);

    return 0;
}

    void read_square_matrix_in_place(const int n, const int m, char matrix[n][m])
    {
        for (int i = 0; i < n; ++i)
            scanf("%s", matrix[i]);
    }

    void change_matrix_to_cavity_map(const int n, const int m, char matrix[n][m])
    {
        const char cavity = 'X';
        for (int i = 1, new_size = n - 1; i < new_size; ++i)
            for (int j = 1; j < new_size; ++j)
                if (is_cell_cavity(n, m, matrix, i, j))
                    matrix[i][j] = cavity;
    }

        bool is_cell_cavity(const int n, const int m, const char matrix[n][m], const int i, const int j)
        {
            return matrix[i - 1][j] < matrix[i][j]
                   && matrix[i][j - 1] < matrix[i][j]
                   && matrix[i + 1][j] < matrix[i][j]
                   && matrix[i][j + 1] < matrix[i][j];
        }
