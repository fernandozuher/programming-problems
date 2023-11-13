# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import math

def main():

    n = int(input())
    matrix = read_matrix(n)
    print(diagonalDifference(matrix))


def read_matrix(n):

    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    return matrix


def diagonalDifference(matrix):

    primary_diagonal, secondary_diagonal = 0, 0
    primary_diagonal_range = range(len(matrix))
    secondary_diagonal_range = range(len(matrix)-1, -1, -1)

    for i, j in zip(primary_diagonal_range, secondary_diagonal_range):
        primary_diagonal += matrix[j][j]
        secondary_diagonal += matrix[j][i]

    return abs(primary_diagonal - secondary_diagonal)


if __name__ == '__main__':
    main()
