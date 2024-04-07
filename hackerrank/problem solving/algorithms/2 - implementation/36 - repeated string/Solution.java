// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        String inputString = scan.nextLine();
        long nCharacters = scan.nextLong();
        final char letter = 'a';
        System.out.println(countInRepeatedString(inputString, letter, nCharacters));
    }

        public static long countInRepeatedString(final String inputString, final char letter, final long nCharacters) {
            long repeatedEntireString = nCharacters / inputString.length();
            long nSubstring = nCharacters % inputString.length();
            var substring = inputString.substring(0, (int) nSubstring);

            long quantity = inputString.chars().filter(x -> x == letter).count();
            quantity *= repeatedEntireString;
            quantity += substring.chars().filter(x -> x == letter).count();

            return quantity;
        }
}
