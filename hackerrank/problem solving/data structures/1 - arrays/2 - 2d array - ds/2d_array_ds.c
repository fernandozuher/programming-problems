// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

#define MATRIX_SIZE 6

int max_hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE]);
int hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int i, int j);

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i)
        for (int j = 0; j < MATRIX_SIZE; ++j)
            scanf("%d", &matrix[i][j]);

    printf("%d", max_hourglass_sum(matrix));

    return 0;
}

// T: O(1)
// S: O(1) extra space
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

int hourglass_sum(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int i, int j)
{
    int subrow_1_first_index = i - 1;
    int subrow_3_first_index = i + 1;
    int first_col_index = j - 1;

    int subrow_1_sum = matrix[subrow_1_first_index][first_col_index] + matrix[subrow_1_first_index][first_col_index + 1]
                       + matrix[subrow_1_first_index][first_col_index + 2];
    int subrow_3_sum = matrix[subrow_3_first_index][first_col_index] + matrix[subrow_3_first_index][first_col_index + 1]
                       + matrix[subrow_3_first_index][first_col_index + 2];

    return subrow_1_sum + matrix[i][j] + subrow_3_sum;
}
