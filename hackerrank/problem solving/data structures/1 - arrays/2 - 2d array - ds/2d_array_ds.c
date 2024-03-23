// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

#define MATRIX_SIZE 6

int max_hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE]);
    int hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const int i, const int j);
        int slice_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const int i, const int j, const int size);

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
            int subrow_1_first_index = i - 1;
            int subrow_3_first_index = i + 1;
            int first_col_index = j - 1;
            const int n = 3;

            int subrow_1_sum = slice_sum(matrix, subrow_1_first_index, first_col_index, n);
            int subrow_3_sum = slice_sum(matrix, subrow_3_first_index, first_col_index, n);

            return subrow_1_sum + matrix[i][j] + subrow_3_sum;
        }

            int slice_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const int i, const int j, const int n)
            {
                int sum = 0;
                for (int k = j, n2 = k + n; k < n2; ++k)
                    sum += matrix[i][k];
                return sum;
            }
