// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.lang.Math;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_TEST_CASES = _readANumber();
        List<Integer> output = Arrays.asList(new Integer[N_TEST_CASES]);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final int BEGIN = _readANumber();
            final int END = _readANumber();

            final SherlockAndSquares OBJ = new SherlockAndSquares(BEGIN, END);
            output.set(i, OBJ.getQuantityOfSquareIntegers());
        }

        printArray(output);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        public static void printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}

    class SherlockAndSquares {
        private int _begin;
        private int _end;
        private int _quantityOfSquareIntegers;

        public SherlockAndSquares(int begin, int end) {
            _begin = begin;
            _end = end;
            _quantityOfSquareIntegers = 0;

            _calculateNumberOfSquareIntegersInRange();
        }

            private void _calculateNumberOfSquareIntegersInRange() {
                for (int number = _findFirstSquareIntegerFromBeginNumber(); _isPowerOf2OfNumberLessThanOrEqualToEndNumber(number); number++)
                    _quantityOfSquareIntegers++;
            }

            private int _findFirstSquareIntegerFromBeginNumber() {
                final double SQUARE_ROOT_NUMBER = Math.sqrt(_begin);
                final int SQUARE_INTEGER = _getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER);
                return SQUARE_INTEGER;
            }

                private int _getSquareIntegerFromNumber(double number) {
                    final int INTEGER_PART = (int) Math.floor(number);
                    return number == INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
                }

            private boolean _isPowerOf2OfNumberLessThanOrEqualToEndNumber(int number) {
                return Math.pow(number, 2) <= _end;
            }

        public int getQuantityOfSquareIntegers() {
            return _quantityOfSquareIntegers;
        }
    }
