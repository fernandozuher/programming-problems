// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_ROWS_COLUMNS 6

int** read_matrix();
int calculate_max_sum(int **matrix);
    int sum_around(int **matrix, const int i, const int j);
int** free_matrix(int **matrix);

int main()
{
    int **matrix = read_matrix();
    const int max_sum = calculate_max_sum(matrix);

    printf("%d\n", max_sum);
    matrix = free_matrix(matrix);

    return 0;
}

    int** read_matrix()
    {
        int **matrix = calloc(N_ROWS_COLUMNS, sizeof(int*));

        for (int i = 0; i < N_ROWS_COLUMNS; ++i) {
            matrix[i] = calloc(N_ROWS_COLUMNS, sizeof(int));

            for (int j = 0; j < N_ROWS_COLUMNS; ++j)
                scanf("%d", &matrix[i][j]);
        }

        return matrix;
    }

    int calculate_max_sum(int **matrix)
    {
        int max_sum = INT_MIN;

        for (int i = 1, before_rows_columns_limit = 5; i < before_rows_columns_limit; ++i)
            for (int j = 1; j < before_rows_columns_limit; ++j) {
                const int current_sum = sum_around(matrix, i, j);

                if (current_sum > max_sum)
                    max_sum = current_sum;
            }

        return max_sum;
    }

        int sum_around(int **matrix, const int i, const int j)
        {
            return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1]
                   + matrix[i][j]
                   + matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
        }

    int** free_matrix(int **matrix)
    {
        for (int i = 0; i < N_ROWS_COLUMNS; ++i)
            free(matrix[i]);
        free(matrix);
        return NULL;
    }
