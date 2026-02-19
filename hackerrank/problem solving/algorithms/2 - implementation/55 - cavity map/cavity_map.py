# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main():
    n = int(input())
    matrix = [list(input()) for _ in range(n)]
    change_matrix_to_cavity_map(matrix)
    for line in matrix:
        print(''.join(line))


# n: length of rows/cols of matrix
# T: O(n^2)
# S: O(n^2) extra space
def change_matrix_to_cavity_map(matrix):
    subrange = range(1, len(matrix) - 1)
    cavities = [(i, j) for i in subrange for j in subrange if is_cell_cavity(matrix, i, j)]
    for i, j in cavities:
        matrix[i][j] = 'X'


def is_cell_cavity(matrix, i, j):
    indexes = valid_indexes(i, j)
    cell = matrix[i][j]
    return all(matrix[r][c] < cell for r, c in indexes)


def valid_indexes(i, j):
    return [(i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1)]


if __name__ == '__main__':
    main()
