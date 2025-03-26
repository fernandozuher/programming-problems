// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            for (int nTests = scan.nextInt(); nTests-- > 0; ) {
                int n = scan.nextInt();
                int p = scan.nextInt();
                power(n, p);
            }
        }
    }

    private static void power(int n, int p) {
        try {
            System.out.println(Calculator.power(n, p));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}

class Calculator {
    public static int power(int n, int p) throws IllegalArgumentException {
        if (n < 0 || p < 0)
            throw new IllegalArgumentException("n and p should be non-negative");
        return (int) Math.pow(n, p);
    }
}
