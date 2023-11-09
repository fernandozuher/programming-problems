// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

import java.util.Scanner;

public class SolveMeFirst {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int num1 = scan.nextInt();
        int num2 = scan.nextInt();
        System.out.println(solveMeFirst(num1, num2));
    }

        private static int solveMeFirst(final int a, final int b) {
            return a + b;
        }
}
