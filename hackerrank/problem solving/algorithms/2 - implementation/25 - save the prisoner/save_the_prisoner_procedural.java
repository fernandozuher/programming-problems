// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;


public class Solution {

    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nTestCases = _readANumber();
        final List<Integer> prisonersChairNumberToWarn = _readTestCasesAndSaveThePrisoners(nTestCases);

        printResults(prisonersChairNumberToWarn);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static List<Integer> _readTestCasesAndSaveThePrisoners(int nTestCases) {
            List<Integer> prisonersChairNumberToWarn = Arrays.asList(new Integer[nTestCases]);

            for (int i = 0; i < nTestCases; i++) {
                List<Integer> testCase = _readTestCase();
                prisonersChairNumberToWarn.set(i, _saveThePrisoner(testCase));
            }

            return prisonersChairNumberToWarn;
        }

            private static List<Integer> _readTestCase() {
                final int TEST_CASE_SIZE = 3;
                List<Integer> testCase = Arrays.asList(new Integer[TEST_CASE_SIZE]);

                for (int i = 0; i < TEST_CASE_SIZE; i++) {
                    final int NUMBER = _scanner.nextInt();
                    testCase.set(i, NUMBER);
                }

                return testCase;
            }

            private static int _saveThePrisoner(List<Integer> testCase) {
                final int PRISONERS = testCase.get(0);
                final int SWEETS = testCase.get(1);
                final int CHAIRNUMBERTOBEGIN = testCase.get(2);
                int prisonerChairNumberToWarn = CHAIRNUMBERTOBEGIN + (SWEETS - 1);

                if (prisonerChairNumberToWarn > PRISONERS) {
                    prisonerChairNumberToWarn %= PRISONERS;

                    if (prisonerChairNumberToWarn == 0)
                        prisonerChairNumberToWarn = PRISONERS;
                }

                return prisonerChairNumberToWarn;
            }

        public static void printResults(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
