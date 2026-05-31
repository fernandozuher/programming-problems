// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true
// Java 25

void main() {
    var matrix = readMatrix();
    IO.println(maxHourglassSum(matrix));
}

int[][] readMatrix() {
    final int n = 6;
    var matrix = new int[n][n];
    for (int i = 0; i < n; i++)
        System.arraycopy(readNumbers(), 0, matrix[i], 0, n);

    return matrix;
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// T: O(1)
// S: O(1) extra space
int maxHourglassSum(int[][] matrix) {
    int maxSum = Integer.MIN_VALUE;

    for (int i = 1, rowsCols = 4; i <= rowsCols; i++)
        for (int j = 1; j <= rowsCols; j++) {
            int currentSum = hourglassSum(matrix, i, j);
            maxSum = Math.max(maxSum, currentSum);
        }

    return maxSum;
}

int hourglassSum(int[][] matrix, int i, int j) {
    int subrow1FirstIndex = i - 1;
    int subrow3FirstIndex = i + 1;
    int firstColIndex = j - 1;
    final int end = firstColIndex + 3;

    int subrow1Sum = Arrays.stream(matrix[subrow1FirstIndex], firstColIndex, end).sum();
    int subrow3Sum = Arrays.stream(matrix[subrow3FirstIndex], firstColIndex, end).sum();

    return subrow1Sum + matrix[i][j] + subrow3Sum;
}
