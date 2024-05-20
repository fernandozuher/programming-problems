# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main():
    n_rows_columns = int(input())
    matrix = [[*input()] for _ in range(n_rows_columns)]
    change_matrix_to_cavity_map(matrix)
    [print(''.join(line)) for line in matrix]


def change_matrix_to_cavity_map(matrix):
    CAVITY = 'X'
    subrange = range(1, len(matrix) - 1)
    for i in subrange:
        for j in subrange:
            if is_cell_cavity(matrix, i, j):
                matrix[i][j] = CAVITY


def is_cell_cavity(matrix, i, j):
    return matrix[i - 1][j] < matrix[i][j] \
        and matrix[i][j - 1] < matrix[i][j] \
        and matrix[i + 1][j] < matrix[i][j] \
        and matrix[i][j + 1] < matrix[i][j]


if __name__ == '__main__':
    main()
