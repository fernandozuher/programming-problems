// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.lang.Math;

public class SherlockAndSquares {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_TEST_CASES = _readANumber();
        List<Integer> output = Arrays.asList(new Integer[N_TEST_CASES]);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final int BEGIN = _readANumber();
            final int END = _readANumber();
            output.set(i, _calculateNumberOfSquareIntegersInRange(BEGIN, END));
        }

        printArray(output);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static int _calculateNumberOfSquareIntegersInRange(int begin, int end) {
            int squares = 0;
            for (int number = _findFirstSquareIntegerFromNumber(begin); _isPowerOf2OfNumberLessThanOrEqualToLimit(number, end); number++)
                squares++;
            return squares;
        }

            private static int _findFirstSquareIntegerFromNumber(int number) {
                final double SQUARE_ROOT_NUMBER = Math.sqrt(number);
                final int SQUARE_INTEGER = _getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
                return SQUARE_INTEGER;
            }

                private static int _getSquareIntegerFromNumber(double number) {
                    final int INTEGER_PART = (int) Math.floor(number);
                    return number == INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
                }

            private static boolean _isPowerOf2OfNumberLessThanOrEqualToLimit(int number, int limit) {
                return Math.pow(number, 2) <= limit;
            }

        public static void printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
