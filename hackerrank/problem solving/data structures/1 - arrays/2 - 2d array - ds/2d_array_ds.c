// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

#define MATRIX_SIZE 6

int max_hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE]);
    int hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const int i, const int j);

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i)
        for (int j = 0; j < MATRIX_SIZE; ++j)
            scanf("%d", &matrix[i][j]);

    printf("%d", max_hourglass_sum(matrix));

    return 0;
}

    int max_hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
    {
        int max_sum = INT_MIN;

        for (int i = 1, rows_cols = 4; i <= rows_cols; ++i)
            for (int j = 1; j <= rows_cols; ++j) {
                int current_sum = hourglass_sum(matrix, i, j);
                max_sum = current_sum > max_sum ? current_sum : max_sum;
            }

        return max_sum;
    }

        int hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const int i, const int j)
        {
            return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1]
                   + matrix[i][j] +
                   matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
        }
