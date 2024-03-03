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

    return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] \
           + matrix[i][j] + \
           matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]


if __name__ == '__main__':
    main()
