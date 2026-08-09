# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    matrix = [list(morfo.read(str)) for _ in range(n)]
    change_matrix_to_cavity_map(matrix)
    for line in matrix:
        print(''.join(line))


# n: length of matrix' rows
# T: O(n^2)
# S: O(1) extra space
def change_matrix_to_cavity_map(matrix):
    subrange = range(1, len(matrix) - 1)
    for i in subrange:
        for j in subrange:
            if is_cell_cavity(matrix, i, j):
                matrix[i][j] = 'X'


def is_cell_cavity(matrix, i, j):
    c = matrix[i][j]
    return matrix[i - 1][j] < c and \
           matrix[i][j - 1] < c and \
           matrix[i + 1][j] < c and \
           matrix[i][j + 1] < c


if __name__ == '__main__':
    main()
