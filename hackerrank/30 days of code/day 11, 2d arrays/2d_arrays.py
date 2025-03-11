# https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

import sys


def main():
    matrix = read_matrix()
    print(calculate_max_sum(matrix))


def read_matrix():
    N_ROWS_COLUMNS = 6
    return [list(map(int, input().split())) for _ in range(N_ROWS_COLUMNS)]


def calculate_max_sum(matrix):
    max_sum = -sys.maxsize - 1
    BEFORE_ROWS_COLUMNS_LIMIT = 5

    for i in range(1, BEFORE_ROWS_COLUMNS_LIMIT):
        for j in range(1, BEFORE_ROWS_COLUMNS_LIMIT):
            max_sum = max(max_sum, sum_around(matrix, i, j))

    return max_sum


def sum_around(matrix, i, j):
    return (matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
            matrix[i][j] +
            matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1])


if __name__ == "__main__":
    main()
