// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;


public class Solution {
    private static Scanner _scanner;

    public static void main(String args[]) {
        _scanner = new Scanner(System.in);
        final int N_TEST_CASES = _readANumber();
        List<Integer> output = Arrays.asList(new Integer[N_TEST_CASES]);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final int NUMBER = _readANumber();
            output.set(i, _findNumberDivisorsQuantity(NUMBER));
        }

        printOutput(output);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static int _findNumberDivisorsQuantity(int NUMBER) {
            int divisors = 0;

            for (int number = NUMBER; number != 0; number /= 10) {
                final int POTENTIAL_DIVISOR = number % 10;
                if (_isNumberEvenlyDividedByDivisor(NUMBER, POTENTIAL_DIVISOR))
                    divisors++;
            }

            return divisors;
        }

            private static boolean _isNumberEvenlyDividedByDivisor(int NUMBER, int DIVISOR) {
                return DIVISOR != 0 && NUMBER % DIVISOR == 0;
            }

        public static void printOutput(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
