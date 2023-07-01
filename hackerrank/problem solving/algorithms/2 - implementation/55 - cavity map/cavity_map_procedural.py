# Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main():

    N_ROWS_COLUMNS = int(input())
    matrix = [[*input()] for _ in range(N_ROWS_COLUMNS)]
    change_matrix_to_cavity_map(matrix)
    [print("".join(line)) for line in matrix]


def change_matrix_to_cavity_map(matrix):

    CAVITY = 'X'
    for i in range(1, len(matrix) - 1):
        for j in range(1, len(matrix) - 1):
            if is_cell_cavity(matrix, i, j):
                matrix[i][j] = CAVITY


def is_cell_cavity(matrix, i, j):

    return matrix[i - 1][j] < matrix[i][j] \
           and matrix[i][j - 1] < matrix[i][j] \
           and matrix[i + 1][j] < matrix[i][j] \
           and matrix[i][j + 1] < matrix[i][j]


if __name__ == "__main__":
    main()
