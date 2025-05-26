// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            final int n = 5;
            int[] numbers = readNumbers(scan, n);
            long[] minMaxSum = calcMinMaxSum(numbers);
            System.out.println(minMaxSum[0] + " " + minMaxSum[1]);
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static long[] calcMinMaxSum(int[] numbers) {
        long sum, min, max;
        sum = min = max = numbers[0];

        for (int i = 1; i < numbers.length; i++) {
            sum += numbers[i];
            min = Math.min(min, numbers[i]);
            max = Math.max(max, numbers[i]);
        }

        return new long[]{sum - max, sum - min};
    }
}
