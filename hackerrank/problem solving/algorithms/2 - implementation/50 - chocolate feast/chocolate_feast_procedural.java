// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class ChocolateFeast {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nTestCases = _scanner.nextInt();
        final List<Integer> output = _solveTestCases(nTestCases);
        output.forEach(System.out::println);
    }

        private static List<Integer> _solveTestCases(int nTestCases) {
            List<Integer> output = Arrays.asList(new Integer[nTestCases]);

            for (int i = 0; i < nTestCases; i++) {
                final int amountOfMoney = _scanner.nextInt();
                final int chocolateBarCost = _scanner.nextInt();
                final int nWrappersToTurnInBar = _scanner.nextInt();
                output.set(i, _howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar));
            }

            return output;
        }

            private static int _howManyChocolatesCanBeEaten(int amountOfMoney, int chocolateBarCost, int nWrappersToTurnInBar) {
                int eatenChocolates = amountOfMoney / chocolateBarCost;

                for (int availableWrappers = eatenChocolates, chocolatesForFree; availableWrappers >= nWrappersToTurnInBar; ) {
                    chocolatesForFree = availableWrappers / nWrappersToTurnInBar;
                    availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree;
                    eatenChocolates += chocolatesForFree;
                }

                return eatenChocolates;
            }
}
