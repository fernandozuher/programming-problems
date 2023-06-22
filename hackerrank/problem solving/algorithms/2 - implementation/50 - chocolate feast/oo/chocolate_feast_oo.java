// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class Solution {
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

                final ChocolateFeast OBJ = new ChocolateFeast(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
                output.set(i, OBJ.getEatenChocolates());
            }

            return output;
        }
}

    class ChocolateFeast {
        private int _amountOfMoney, _chocolateBarCost, _nWrappersToTurnInBar;
        private int _eatenChocolates;

        public ChocolateFeast(int amountOfMoney, int chocolateBarCost, int nWrappersToTurnInBar) {
            _amountOfMoney = amountOfMoney;
            _chocolateBarCost = chocolateBarCost;
            _nWrappersToTurnInBar = nWrappersToTurnInBar;
            _eatenChocolates = 0;

            _calculateHowManyChocolatesCanBeEaten();
        }

            private void _calculateHowManyChocolatesCanBeEaten() {
                _eatenChocolates = _amountOfMoney / _chocolateBarCost;

                for (int availableWrappers = _eatenChocolates; availableWrappers >= _nWrappersToTurnInBar; ) {
                    int chocolatesForFree = availableWrappers / _nWrappersToTurnInBar;
                    availableWrappers = availableWrappers - (chocolatesForFree * _nWrappersToTurnInBar) + chocolatesForFree;
                    _eatenChocolates += chocolatesForFree;
                }
            }

        public int getEatenChocolates() {
            return _eatenChocolates;
        }
    }
