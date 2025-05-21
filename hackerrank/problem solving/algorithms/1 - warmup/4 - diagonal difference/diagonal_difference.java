// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            System.out.println(diagonalDifference(scan, n));
        }
    }

    private static int diagonalDifference(Scanner scan, int n) {
        int primarySum = 0, secondarySum = 0;

        for (int i = 0; i < n; i++) {
            int[] numbers = readNumbers(scan);
            primarySum += numbers[i];
            secondarySum += numbers[n - i - 1];
        }

        return Math.abs(primarySum - secondarySum);
    }

    private static int[] readNumbers(Scanner scan) {
        return Arrays.stream(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}
