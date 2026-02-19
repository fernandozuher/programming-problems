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

// n: length of rows/cols of matrix
// T: O(n^2)
// S: O(1) extra space
void changeMatrixToCavityMap(char[][] matrix) {
    for (int i = 1, n = matrix.length - 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (isCellCavity(matrix, i, j)) matrix[i][j] = 'X';
}

boolean isCellCavity(char[][] matrix, int i, int j) {
    char c = matrix[i][j];
    return matrix[i - 1][j] < c &&
           matrix[i][j - 1] < c &&
           matrix[i + 1][j] < c &&
           matrix[i][j + 1] < c;
}
