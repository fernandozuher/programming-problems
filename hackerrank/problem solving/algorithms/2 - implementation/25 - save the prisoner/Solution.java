// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);

        int n = scan.nextInt();
        var prisonersChairNumberToWarn = Arrays.asList(new Integer[n]);

        for (int i = 0; i < n; ++i) {
            int prisoners = scan.nextInt();
            int sweets = scan.nextInt();
            int chairNumberToBegin = scan.nextInt();
            prisonersChairNumberToWarn.set(i, saveThePrisoner(prisoners, sweets, chairNumberToBegin));
        }

        prisonersChairNumberToWarn.forEach(System.out::println);
    }

        private static int saveThePrisoner(final int prisoners, final int sweets, final int chairNumberToBegin) {
            int prisonerChairNumberToWarn = chairNumberToBegin + (sweets - 1);
            int x = prisonerChairNumberToWarn;

            if (x > prisoners) {
                x %= prisoners;
                if (x == 0)
                    x = prisoners;
            }

            return x;
        }
}
