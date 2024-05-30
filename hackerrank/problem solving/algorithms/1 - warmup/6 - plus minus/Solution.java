// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// From Java 21

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<Double> result = plusMinus(n);
        double positiveProportion = result.getFirst();
        double negativeProportion = result.get(1);
        double zeroProportion = result.getLast();

        System.out.printf("%.6f\n", positiveProportion);
        System.out.printf("%.6f\n", negativeProportion);
        System.out.printf("%.6f\n", zeroProportion);
    }

        public static List<Double> plusMinus(final int n) {
            int positive = 0;
            int negative = 0;
            int zero = 0;

            for (int i = 0; i < n; ++i) {
                int x = scan.nextInt();
                if (x > 0)
                    ++positive;
                else if (x < 0)
                    ++negative;
                else
                    ++zero;
            }

            double positiveProportion = (double) positive / n;
            double negativeProportion = (double) negative / n;
            double zeroProportion = (double) zero / n;

            return Arrays.asList(positiveProportion, negativeProportion, zeroProportion);
        }
}
