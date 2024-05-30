// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(diagonalDifference(n));
    }

        public static int diagonalDifference(final int n) {
            int primaryDiagonal = 0, secondaryDiagonal = 0;
    
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    int x = scan.nextInt();
                    if (i == j)
                        primaryDiagonal += x;
                    if (j == n - i - 1)
                        secondaryDiagonal += x;
                }
    
            return Math.abs(primaryDiagonal - secondaryDiagonal);
        }
}
