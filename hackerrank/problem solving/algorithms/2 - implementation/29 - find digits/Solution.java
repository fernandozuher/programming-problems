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

        private static int _findNumberDivisorsQuantity(int number) {
            int divisors = 0;

            for (int currentNumber = number; currentNumber != 0; currentNumber = _removeLastDigitOfNumber(currentNumber)) {
                final int DIVISOR = _getLastDigitOfNumber(currentNumber);
                if (_isNumberEvenlyDividedByDivisor(number, DIVISOR))
                    divisors++;
            }

            return divisors;
        }

            private static int _getLastDigitOfNumber(int number) {
                return number % 10;
            }

            private static boolean _isNumberEvenlyDividedByDivisor(int number, int divisor) {
                return divisor != 0 && number % divisor == 0;
            }

            private static int _removeLastDigitOfNumber(int number) {
                return number / 10;
            }

        public static void printOutput(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
