// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char** read_square_matrix(const int size);
void change_matrix_to_cavity_map(char** matrix, const int size);
    bool is_cell_cavity(const char** matrix, const int i, const int j);
char** free_matrix(char** matrix, const int size);

int main()
{
    int n_rows_columns;
    scanf("%d", &n_rows_columns);

    char** matrix = read_square_matrix(n_rows_columns);

    change_matrix_to_cavity_map(matrix, n_rows_columns);
    for (int i = 0; i < n_rows_columns; printf("%s\n", matrix[i++]));

    matrix = free_matrix(matrix, n_rows_columns);

    return 0;
}

    char** read_square_matrix(const int size)
    {
        char** matrix = (char**) calloc(size, sizeof(char*));
        const int terminator = 1;

        for (int i = 0; i < size; ++i) {
            matrix[i] = (char*) calloc(size + terminator, sizeof(char));
            scanf("%s", matrix[i]);
        }

        return matrix;
    }

    void change_matrix_to_cavity_map(char** matrix, const int size)
    {
        const char cavity = 'X';
        for (int i = 1, new_size = size - 1; i < new_size; ++i)
            for (int j = 1; j < new_size; ++j)
                if (is_cell_cavity(matrix, i, j))
                    matrix[i][j] = cavity;
    }

        bool is_cell_cavity(const char** matrix, int i, int j)
        {
            return matrix[i - 1][j] < matrix[i][j]
                   && matrix[i][j - 1] < matrix[i][j]
                   && matrix[i + 1][j] < matrix[i][j]
                   && matrix[i][j + 1] < matrix[i][j];
        }

    char** free_matrix(char** matrix, const int size)
    {
        for (int i = 0; i < size; ++i)
            free(matrix[i]);
        return NULL;
    }
