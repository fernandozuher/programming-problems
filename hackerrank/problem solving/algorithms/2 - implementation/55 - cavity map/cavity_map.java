// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// Java 25

void main() {
    int n = Integer.parseInt(IO.readln());
    char[][] matrix = readMatrix(n);
    changeMatrixToCavityMap(matrix);
    for (var x : matrix)
        IO.println(new String(x));
}

char[][] readMatrix(int n) {
    return IntStream.range(0, n).mapToObj(_ -> IO.readln().toCharArray()).toArray(char[][]::new);
}

void changeMatrixToCavityMap(char[][] matrix) {
    for (int i = 1, n = matrix.length - 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (isCellCavity(matrix, i, j))
                matrix[i][j] = 'X';
}

boolean isCellCavity(char[][] matrix, int i, int j) {
    return matrix[i - 1][j] < matrix[i][j] &&
            matrix[i][j - 1] < matrix[i][j] &&
            matrix[i + 1][j] < matrix[i][j] &&
            matrix[i][j + 1] < matrix[i][j];
}
