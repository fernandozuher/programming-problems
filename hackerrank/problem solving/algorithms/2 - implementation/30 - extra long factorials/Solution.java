// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int number = scan.nextInt();
        BigInteger factorial = calculateFactorialOf(number);
        System.out.println(factorial);
    }

        private static BigInteger calculateFactorialOf(final int number) {
            BigInteger factorial = BigInteger.ONE;
            for (int currentNumber = 2; currentNumber <= number; ++currentNumber)
                factorial = factorial.multiply(BigInteger.valueOf(currentNumber));
            return factorial;
        }
}
