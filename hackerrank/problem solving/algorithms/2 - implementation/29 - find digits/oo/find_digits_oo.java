// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;


public class Solution {
    private static Scanner _scanner;

    public static void main(String args[]) {
        _scanner = new Scanner(System.in);
        final int N_tEST_cASES = _readANumber();
        List<Integer> output = Arrays.asList(new Integer[N_tEST_cASES]);

        for (int i = 0; i < N_tEST_cASES; i++) {
            final int NUMBER = _readANumber();
            final FindDigits OBJ = new FindDigits(NUMBER);
            output.set(i, OBJ.getDivisors());
        }

        printOutput(output);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        public static void printOutput(List<Integer> array) {
            array.forEach(System.out::println);
        }
}

    class FindDigits {
        private int _number;
        private int _divisors;

        public FindDigits(int number) {
            _number = number;
            _divisors = 0;
            _findNumberDivisorsQuantity();
        }

            private void _findNumberDivisorsQuantity() {
                for (int currentNumber = _number; currentNumber != 0; currentNumber = _removeLastDigitOfNumber(currentNumber)) {
                    final int DIVISOR = _getLastDigitOfNumber(currentNumber);
                    if (_isNumberEvenlyDividedByDivisor(DIVISOR))
                        _divisors++;
                }
            }

                private int _getLastDigitOfNumber(int number) {
                    return number % 10;
                }

                private boolean _isNumberEvenlyDividedByDivisor(int divisor) {
                    return divisor != 0 && _number % divisor == 0;
                }

                private int _removeLastDigitOfNumber(int number) {
                    return number / 10;
                }

        public int getDivisors() {
            return _divisors;
        }
    }
