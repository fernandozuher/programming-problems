// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class ModifiedKrapekarNumbers {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int lowerLimit = _scanner.nextInt();
        final int upperLimit = _scanner.nextInt();

        final List<Integer> output = _findKaprekarNumbersInRange(lowerLimit, upperLimit);
        printOutput(output);
    }

        private static List<Integer> _findKaprekarNumbersInRange(int lowerLimit, int upperLimit) {
            List<Integer> kaprekarNumbers = new ArrayList<Integer>();

            for (int number = lowerLimit; number <= upperLimit; number++) {
                final int potentialKaprekarNumber = _calculatePotentialKaprekarNumber(number);
                if (number == potentialKaprekarNumber)
                    kaprekarNumbers.add(number);
            }

            return kaprekarNumbers;
        }

            private static int _calculatePotentialKaprekarNumber(int number) {
                final Long longLongNumber = Long.parseUnsignedLong(Integer.toString(number));
                final String squareNumberInString = Long.toUnsignedString(longLongNumber * longLongNumber);
                final int lengthOfNumberInString = Integer.toString(number).length();

                final String leftNumberInString = _getLeftNumberInString(squareNumberInString, lengthOfNumberInString);
                final String rightNumberInString = _getRightNumberInString(squareNumberInString, lengthOfNumberInString);

                final int potentialKaprekarNumber = _sumNumbersInStrings(leftNumberInString, rightNumberInString);

                return potentialKaprekarNumber;
            }

                private static String _getLeftNumberInString(String squareNumberInString, int lengthOfNumberInString) {
                    final int digitsToSkip = 0;
                    final int digitsToTake = squareNumberInString.length() - lengthOfNumberInString;
                    final String numberInString = squareNumberInString.substring(digitsToSkip, digitsToTake);
                    return numberInString;
                }

                private static String _getRightNumberInString(String squareNumberInString, int lengthOfNumberInString) {
                    final int digitsToSkip = squareNumberInString.length() - lengthOfNumberInString;
                    final String numberInString = squareNumberInString.substring(digitsToSkip);
                    return numberInString;
                }

                private static int _sumNumbersInStrings(String leftNumberInString, String rightNumberInString) {
                    if (leftNumberInString.length() > 0 && rightNumberInString.length() > 0)
                        return Integer.parseInt(leftNumberInString) + Integer.parseInt(rightNumberInString);
                    else if (leftNumberInString.length() == 0)
                        return Integer.parseInt(rightNumberInString);
                    else if (rightNumberInString.length() == 0)
                        return Integer.parseInt(leftNumberInString);
                    return 0;
                }

        public static void printOutput(List<Integer> array) {
            if (!array.isEmpty())
                array.forEach(element -> System.out.print(element + " "));
            else
                System.out.println("INVALID RANGE");
        }
}
