// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            for (int testCases = scan.nextInt(); testCases-- > 0; ) {
                int n = scan.nextInt();
                int k = scan.nextInt();
                System.out.println(bitwiseAnd(n, k));
            }
        }
    }

    private static int bitwiseAnd(int n, int k) {
        if ((k - 1 | k) <= n)
            return k - 1;
        return k - 2;
    }
}
