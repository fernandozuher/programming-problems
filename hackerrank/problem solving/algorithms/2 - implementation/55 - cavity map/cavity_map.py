# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main():
    n = int(input())
    matrix = [list(input()) for _ in range(n)]
    change_matrix_to_cavity_map(matrix)
    for line in matrix:
        print(''.join(line))


def change_matrix_to_cavity_map(matrix):
    subrange = range(1, len(matrix) - 1)
    for i in subrange:
        for j in subrange:
            if is_cell_cavity(matrix, i, j):
                matrix[i][j] = 'X'


def is_cell_cavity(matrix, i, j):
    return matrix[i - 1][j] < matrix[i][j] \
        and matrix[i][j - 1] < matrix[i][j] \
        and matrix[i + 1][j] < matrix[i][j] \
        and matrix[i][j + 1] < matrix[i][j]


if __name__ == '__main__':
    main()
