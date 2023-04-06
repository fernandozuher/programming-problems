// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final String INITIAL_STRING = _readAWord();
        final String FINAL_STRING = _readAWord();
        final int NUMBER_OF_OPERATIONS = _readANumber();

        final AppendAndDelete OBJ = new AppendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
        final boolean RESPONSE = OBJ.getResponse();
        printOutput(RESPONSE);
    }

    private static String _readAWord() {
        return _scanner.next();
    }

    private static int _readANumber() {
        return _scanner.nextInt();
    }

    public static void printOutput(boolean response) {
        System.out.println(response ? "Yes" : "No");
    }
}

    class AppendAndDelete {
        private String _initialString;
        private String _finalString;
        private int _numberOfOperations;

        private int _commonPrefixSizeBetweenStrings;
        private boolean _areOperationsSuitableToReplacement;

        public AppendAndDelete(String initialString, String finalString, int numberOfOperations) {
            _initialString = initialString;
            _finalString = finalString;
            _numberOfOperations = numberOfOperations;

            _appendAndDelete();
        }

            private void _appendAndDelete() {
                _commonPrefixSizeBetweenStrings = _findCommonPrefixSizeBetweenStrings();

                final int SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = _initialString.length() - _commonPrefixSizeBetweenStrings;
                final int SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = _finalString.length() - _commonPrefixSizeBetweenStrings;

                final int MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;

                _numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;
                _areOperationsSuitableToReplacement = _areOperationsSuitableToReplaceString();
            }

                private int _findCommonPrefixSizeBetweenStrings() {
                    int size = 0;
                    while (size != _initialString.length() && size != _finalString.length() && _initialString.charAt(size) == _finalString.charAt(size))
                        size++;
                    return size;
                }

                private boolean _areOperationsSuitableToReplaceString() {
                    if (_numberOfOperations < 0 ||
                            (_areOperationsBiggerThanZeroAndOdd() &&
                             _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private boolean _areOperationsBiggerThanZeroAndOdd() {
                        return _numberOfOperations > 0 && _numberOfOperations % 2 == 1;
                    }

                    private boolean _areNotOperationsEnoughToRemoveAndReplaceCommonPrefix() {
                        return _numberOfOperations < _commonPrefixSizeBetweenStrings * 2;
                    }

        public boolean getResponse() {
            return _areOperationsSuitableToReplacement;
        }
    }
