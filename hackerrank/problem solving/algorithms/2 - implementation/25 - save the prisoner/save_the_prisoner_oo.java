// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Stream;
import java.util.stream.Collectors;


public class Solution {

    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);
        final int N_TEST_CASES = _readANumber();
        List<Integer> prisonersChairNumberToWarn = Arrays.asList(new Integer[N_TEST_CASES]);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final List<Integer> TEST_CASE = _readTestCase();
            final SaveThePrisoner OBJ = new SaveThePrisoner(TEST_CASE);
            prisonersChairNumberToWarn.set(i, OBJ.getPrisonerChairNumberToWarn());
        }

        _printResults(prisonersChairNumberToWarn);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            _scanner.nextLine(); // remove remaining new line
            return NUMBER;
        }

        private static List<Integer> _readTestCase() {
            final List<Integer> TEST_CASE = Stream.of(_scanner.nextLine().split(" "))
                                            .map(Integer::parseInt)
                                            .collect(Collectors.toList());
            return TEST_CASE;
        }

        private static void _printResults(List<Integer> array) {
            array.forEach(System.out::println);
        }
}

    class SaveThePrisoner {

        private int _prisoners;
        private int _sweets;
        private int _chairNumberToBegin;
        private int _prisonerChairNumberToWarn;

        public SaveThePrisoner(List<Integer> testCase) {
            _prisoners = testCase.get(0);
            _sweets = testCase.get(1);
            _chairNumberToBegin = testCase.get(2);

            _prisonerChairNumberToWarn = _saveThePrisoner();
        }

            private int _saveThePrisoner() {
                int prisonerChairNumberToWarn = _chairNumberToBegin + (_sweets - 1);

                if (prisonerChairNumberToWarn > _prisoners) {
                    prisonerChairNumberToWarn %= _prisoners;

                    if (prisonerChairNumberToWarn == 0)
                        prisonerChairNumberToWarn = _prisoners;
                }

                return prisonerChairNumberToWarn;
            }

        public int getPrisonerChairNumberToWarn() {
            return _prisonerChairNumberToWarn;
        }
    }
