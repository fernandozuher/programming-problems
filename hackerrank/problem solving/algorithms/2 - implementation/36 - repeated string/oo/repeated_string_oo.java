// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final String INPUT_STRING = _scanner.next();
        final long N_CHARACTERS = _scanner.nextLong();

        final RepeatedString OBJ = new RepeatedString(INPUT_STRING, N_CHARACTERS);
        final long QUANTITY_OF_A = OBJ.getQuantityOfA();
        System.out.println(QUANTITY_OF_A);
    }
}

    class RepeatedString {
        private String _inputString;
        private long _nCharacters;
        private long _quantityOfA;

        public RepeatedString(String inputString, long nCharacters) {
            _inputString = inputString;
            _nCharacters = nCharacters;
            _quantityOfA = 0;

            _findQuantityOfAInRepeatedString();
        }

            private void _findQuantityOfAInRepeatedString() {
                _quantityOfA = _findQuantityOfAInString(_inputString);
                _quantityOfA *= _findQuantityOfRepeatedEntireString();
                _quantityOfA += _findQuantityOfRemainingA();
            }

                private long _findQuantityOfAInString(String inputString) {
                    long quantityOfA = 0;

                    for (char character : inputString.toCharArray())
                        if (character == 'a')
                            quantityOfA++;

                    return quantityOfA;
                }

                private long _findQuantityOfRepeatedEntireString() {
                    final long N_STRINGS = (long) Math.floor(_nCharacters / _inputString.length());
                    return N_STRINGS;
                }

                private long _findQuantityOfRemainingA() {
                    final long N_REMAINING_CHARACTERS_OF_STRING = _nCharacters % _inputString.length();

                    if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                        return 0;

                    final String SUB_STRING = _inputString.substring(0, (int) N_REMAINING_CHARACTERS_OF_STRING);
                    return _findQuantityOfAInString(SUB_STRING);
                }

        public long getQuantityOfA() {
            return _quantityOfA;
        }
    }
