// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);
        final int NUMBER = _scanner.nextInt();
        final BigInteger FACTORIAL = _calculateFactorialOf(NUMBER);
        System.out.println(FACTORIAL);
    }

        private static BigInteger _calculateFactorialOf(int number) {
            BigInteger factorial = BigInteger.ONE;
            for (int i = 2; i <= number; i++)
                factorial = factorial.multiply(BigInteger.valueOf(i));
            return factorial;
        }
}
