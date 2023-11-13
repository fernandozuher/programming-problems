// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int** read_matrix(const int n);
int diagonal_difference(int **matrix, const int n_lines_columns);

int main()
{
    int n;
    scanf("%d", &n);

    int **matrix = read_matrix(n);
    printf("%d\n", diagonal_difference(matrix, n));

    return 0;
}

    int** read_matrix(const int n)
    {
        int **matrix = (int**) calloc(n, sizeof(int*));
        for (int i = 0; i < n; ++i)
            matrix[i] = (int*) calloc(n, sizeof(int));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &matrix[i][j]);

        return matrix;
    }

    int diagonal_difference(int **matrix, const int n_lines_columns)
    {
        int primary_diagonal = 0, secondary_diagonal = 0;

        for (int i = 0, j = n_lines_columns - 1; i < n_lines_columns; ++i, --j) {
            primary_diagonal += matrix[j][j];
            secondary_diagonal += matrix[j][i];
        }

        return abs(primary_diagonal - secondary_diagonal);
    }
