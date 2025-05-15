// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n1 = scan.nextInt();
            int n2 = scan.nextInt();
            System.out.print(solveMeFirst(n1, n2));
        }
    }

    private static int solveMeFirst(int n1, int n2) {
        return n1 + n2;
    }
}
