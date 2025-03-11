// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true
// From C23 onward: auto (changed meaning), nullptr

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_ROWS_COLUMNS 6

int **read_matrix();
int calculate_max_sum(int **const matrix);
int sum_around(int **const matrix, int i, int j);
int max(int a, int b);
int **free_matrix(int **matrix);

int main()
{
    int **matrix = read_matrix();
    printf("%d\n", calculate_max_sum(matrix));
    matrix = free_matrix(matrix);
    return 0;
}

int **read_matrix()
{
    auto matrix = (int **) malloc(N_ROWS_COLUMNS * sizeof(int *));

    for (int i = 0; i < N_ROWS_COLUMNS; ++i) {
        matrix[i] = (int *) malloc(N_ROWS_COLUMNS * sizeof(int));
        for (int j = 0; j < N_ROWS_COLUMNS; ++j)
            scanf("%d", &matrix[i][j]);
    }

    return matrix;
}

int calculate_max_sum(int **const matrix)
{
    int max_sum = INT_MIN;
    for (int i = 1, before_rows_columns_limit = 5; i < before_rows_columns_limit; ++i)
        for (int j = 1; j < before_rows_columns_limit; ++j)
            max_sum = max(max_sum, sum_around(matrix, i, j));
    return max_sum;
}

int sum_around(int **const matrix, int i, int j)
{
    return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1]
           + matrix[i][j]
           + matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int **free_matrix(int **matrix)
{
    for (int i = 0; i < N_ROWS_COLUMNS; ++i)
        free(matrix[i]);
    free(matrix);
    return nullptr;
}
