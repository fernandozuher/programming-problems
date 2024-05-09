// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();

        var output = Arrays.stream(new Integer[n]).map(_ -> {
            int amountOfMoney = scan.nextInt();
            int chocolateBarCost = scan.nextInt();
            int nWrappersToTurnInBar = scan.nextInt();
            return howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
        });

        output.forEach(System.out::println);
    }

        public static int howManyChocolatesCanBeEaten(final int amountOfMoney, final int chocolateBarCost, final int nWrappersToTurnInBar) {
            int eatenChocolates = amountOfMoney / chocolateBarCost;

            for (int availableWrappers = eatenChocolates, chocolatesForFree; availableWrappers >= nWrappersToTurnInBar; ) {
                chocolatesForFree = availableWrappers / nWrappersToTurnInBar;
                availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree;
                eatenChocolates += chocolatesForFree;
            }

            return eatenChocolates;
        }
}
