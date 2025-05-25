// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// Java 22

import java.util.Scanner;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int[] numbers = readNumbers(scan, n);
            double[] ratios = plusMinus(numbers);
            printRatios(ratios);
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static double[] plusMinus(int[] numbers) {
        int positive = 0;
        int negative = 0;
        int zero = 0;

        for (int x : numbers) {
            if (x > 0) ++positive;
            else if (x < 0) ++negative;
            else ++zero;
        }

        double n = numbers.length;
        return new double[]{positive / n, negative / n, zero / n};
    }

    private static void printRatios(double[] ratios) {
        for (double ratio : ratios)
            System.out.printf("%.6f\n", ratio);
    }
}
