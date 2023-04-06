// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final String INITIAL_STRING = _readAWord();
        final String FINAL_STRING = _readAWord();
        final int NUMBER_OF_OPERATIONS = _readANumber();

        final boolean RESPONSE = _appendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
        printOutput(RESPONSE);
    }

        private static String _readAWord() {
            return _scanner.next();
        }

        private static int _readANumber() {
            return _scanner.nextInt();
        }

        private static boolean _appendAndDelete(String initialString, String finalString, int numberOfOperations) {
            final int COMMON_PREFIX_SIZE_BETWEEN_STRINGS = _findCommonPrefixSizeBetweenStrings(initialString, finalString);

            final int SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = initialString.length() - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;
            final int SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = finalString.length() - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;

            final int MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
            numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;

            return _areOperationsSuitableToReplaceString(numberOfOperations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
        }

            private static int _findCommonPrefixSizeBetweenStrings(String initialString, String finalString) {
                int size = 0;
                while (size != initialString.length() && size != finalString.length() && initialString.charAt(size) == finalString.charAt(size))
                    size++;
                return size;
            }

            private static boolean _areOperationsSuitableToReplaceString(int numberOfOperations, int commonPrefixSizeBetweenStrings) {
                if (numberOfOperations < 0 ||
                    (_areOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                        _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)))
                    return false;
                return true;
            }

                private static boolean _areOperationsBiggerThanZeroAndOdd(int numberOfOperations) {
                    return numberOfOperations > 0 && numberOfOperations%2 == 1;
                }

                private static boolean _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(int numberOfOperations, int commonPrefixSizeBetweenStrings) {
                    return numberOfOperations < commonPrefixSizeBetweenStrings*2;
                }

        public static void printOutput(boolean response) {
            System.out.println(response ? "Yes" : "No");
        }
}
