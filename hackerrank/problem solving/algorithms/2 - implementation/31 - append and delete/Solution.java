// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        String initialString = scan.nextLine();
        String finalString = scan.nextLine();
        int operations = scan.nextInt();

        var obj = new AppendAndDelete(initialString, finalString, operations);
        System.out.println(obj.areOperationsSuitableToReplacement() ? "Yes" : "No" );
    }
}

    class AppendAndDelete {
        private String initialString;
        private String finalString;
        private int operations;

        private int commonPrefixSizeBetweenStrings;
        private boolean areOperationsProperToReplacement;

        public AppendAndDelete(final String initialString, final String finalString, final int operations) {
            this.initialString = initialString;
            this.finalString = finalString;
            this.operations = operations;

            commonPrefixSizeBetweenStrings = 0;
            areOperationsProperToReplacement = false;

            appendAndDelete();
        }

            private void appendAndDelete() {
                commonPrefixSizeBetweenStrings = findCommonPrefixSizeBetweenStrings();

                int sizeOfDifferentCharactersFromInitialString = initialString.length() - commonPrefixSizeBetweenStrings;
                int sizeOfDifferentCharactersFromFinalString = finalString.length() - commonPrefixSizeBetweenStrings;

                int minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;

                operations -= minimalQuantityOfOperationsToReplaceString;
                areOperationsProperToReplacement = areOperationsSuitableToReplaceString();
            }

                private int findCommonPrefixSizeBetweenStrings() {
                    int size = 0;
                    int n = Math.min(initialString.length(), finalString.length());
                    while (n-- > 0 && initialString.charAt(size) == finalString.charAt(size))
                        ++size;
                    return size;
                }

                private boolean areOperationsSuitableToReplaceString() {
                    if (operations < 0 ||
                            (areOperationsBiggerThanZeroAndOdd() &&
                             areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    private boolean areOperationsBiggerThanZeroAndOdd() {
                        return operations > 0 && operations % 2 == 1;
                    }

                    private boolean areNotOperationsEnoughToRemoveAndReplaceCommonPrefix() {
                        return operations < commonPrefixSizeBetweenStrings * 2;
                    }

        public boolean areOperationsSuitableToReplacement() {
            return areOperationsProperToReplacement;
        }
    }
