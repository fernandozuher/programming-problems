// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int lowerLimit = _scanner.nextInt();
        final int upperLimit = _scanner.nextInt();

        final KaprekarNumbers obj = new KaprekarNumbers(lowerLimit, upperLimit);
        printOutput(obj.getKaprekarNumbers());
    }

    public static void printOutput(List<Integer> array) {
        if (!array.isEmpty())
            array.forEach(element -> System.out.print(element + " "));
        else
            System.out.println("INVALID RANGE");
    }

}

    class KaprekarNumbers {
        private int _lowerLimit, _upperLimit;
        private List<Integer> _kaprekarNumbers;

        public KaprekarNumbers(int lowerLimit, int upperLimit) {
            _lowerLimit = lowerLimit;
            _upperLimit = upperLimit;
            _kaprekarNumbers = new ArrayList<Integer>();

            _findKaprekarNumbersInRange();
        }

            private void _findKaprekarNumbersInRange() {
                for (int number = _lowerLimit; number <= _upperLimit; number++) {
                    final int potentialKaprekarNumber = _calculatePotentialKaprekarNumber(number);
                    if (number == potentialKaprekarNumber)
                        _kaprekarNumbers.add(number);
                }
            }

                private int _calculatePotentialKaprekarNumber(int number) {
                    final Long longLongNumber = Long.parseUnsignedLong(Integer.toString(number));
                    final String squareNumberInString = Long.toUnsignedString(longLongNumber * longLongNumber);
                    final int lengthOfNumberInString = Integer.toString(number).length();

                    final String leftNumberInString = _getLeftNumberInString(squareNumberInString, lengthOfNumberInString);
                    final String rightNumberInString = _getRightNumberInString(squareNumberInString, lengthOfNumberInString);

                    final int potentialKaprekarNumber = _sumNumbersInStrings(leftNumberInString, rightNumberInString);

                    return potentialKaprekarNumber;
                }

                    private String _getLeftNumberInString(String squareNumberInString, int lengthOfNumberInString) {
                        final int digitsToSkip = 0;
                        final int digitsToTake = squareNumberInString.length() - lengthOfNumberInString;
                        final String numberInString = squareNumberInString.substring(digitsToSkip, digitsToTake);
                        return numberInString;
                    }

                    private String _getRightNumberInString(String squareNumberInString, int lengthOfNumberInString) {
                        final int digitsToSkip = squareNumberInString.length() - lengthOfNumberInString;
                        final String numberInString = squareNumberInString.substring(digitsToSkip);
                        return numberInString;
                    }

                    private int _sumNumbersInStrings(String leftNumberInString, String rightNumberInString) {
                        if (leftNumberInString.length() > 0 && rightNumberInString.length() > 0)
                            return Integer.parseInt(leftNumberInString) + Integer.parseInt(rightNumberInString);
                        else if (leftNumberInString.length() == 0)
                            return Integer.parseInt(rightNumberInString);
                        else if (rightNumberInString.length() == 0)
                            return Integer.parseInt(leftNumberInString);
                        return 0;
                    }

        public List<Integer> getKaprekarNumbers() {
            return _kaprekarNumbers;
        }
    }
