// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import java.util.Scanner;

public class RepeatedString {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final String INPUT_STRING = _scanner.next();
        final long N_CHARACTERS = _scanner.nextLong();

        final long QUANTITY_OF_A = findQuantityOfAInRepeatedString(INPUT_STRING, N_CHARACTERS);
        System.out.println(QUANTITY_OF_A);
    }

    private static long findQuantityOfAInRepeatedString(String inputString, long nCharacters) {
        long quantityOfA = findQuantityOfAInString(inputString);
        quantityOfA *= findQuantityOfRepeatedEntireString(nCharacters, inputString.length());
        quantityOfA += findQuantityOfRemainingA(nCharacters, inputString);

        return quantityOfA;
    }

        private static long findQuantityOfAInString(String inputString) {
            long quantityOfA = 0;

            for (char character : inputString.toCharArray())
                if (character == 'a')
                    quantityOfA++;

            return quantityOfA;
        }

        private static long findQuantityOfRepeatedEntireString(long nCharacters, long sizeString) {
            final long N_STRINGS = (long) Math.floor(nCharacters / sizeString);
            return N_STRINGS;
        }

        private static long findQuantityOfRemainingA(long nCharacters, String inputString) {
            final long N_REMAINING_CHARACTERS_OF_STRING = nCharacters % inputString.length();

            if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                return 0;

            final String SUB_STRING = inputString.substring(0, (int) N_REMAINING_CHARACTERS_OF_STRING);
            return findQuantityOfAInString(SUB_STRING);
        }
}
