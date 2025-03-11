// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

import java.util.Scanner;

class TwoDArrays {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int[][] matrix = readMatrix();
        System.out.println(calculateMaxSum(matrix));
    }

    private static int[][] readMatrix() {
        final int nRowsColumns = 6;
        int[][] matrix = new int[nRowsColumns][nRowsColumns];

        for (int i = 0; i < nRowsColumns; i++)
            for (int j = 0; j < nRowsColumns; j++)
                matrix[i][j] = scan.nextInt();

        return matrix;
    }

    private static int calculateMaxSum(final int[][] matrix) {
        int maxSum = Integer.MIN_VALUE;

        for (int i = 1, beforeRowsColumnsLimit = 5; i < beforeRowsColumnsLimit; i++)
            for (int j = 1; j < beforeRowsColumnsLimit; j++)
                maxSum = Math.max(maxSum, sumAround(matrix, i, j));

        return maxSum;
    }

    private static int sumAround(final int[][] matrix, final int i, final int j) {
        return matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                matrix[i][j] +
                matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
    }
}
