# https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

import sys

def main():

    N = 6
    matrix = [list(map(int, input().split())) for _ in range(N)]
    print(max_hourglass_sum(matrix))


def max_hourglass_sum(matrix):

    max_sum = -sys.maxsize - 1
    rows_cols = range(1, 5)

    for i in rows_cols:
        for j in rows_cols:
            current_sum = hourglass_sum(matrix, i, j)
            max_sum = max(max_sum, current_sum)

    return max_sum


def hourglass_sum(matrix, i, j):

    subrow_1_first_index = i - 1
    subrow_3_first_index = i + 1
    first_col_index = j - 1
    end = first_col_index + 3

    subrow_1_sum = sum(matrix[subrow_1_first_index][first_col_index:end])
    subrow_3_sum = sum(matrix[subrow_3_first_index][first_col_index:end])

    return subrow_1_sum + matrix[i][j] + subrow_3_sum


if __name__ == '__main__':
    main()
