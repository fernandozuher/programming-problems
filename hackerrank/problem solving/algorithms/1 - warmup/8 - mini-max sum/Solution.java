// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// From Java 21

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.Collections;
import static java.util.stream.Collectors.toList;

public class Main {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        final int n = 5;
        List<Integer> array = readIntArray(n);
        Collections.sort(array);

        List<Long> result = miniMaxSum(array);
        long minSum = result.getFirst();
        long maxSum = result.getLast();
        System.out.print(minSum + " " + maxSum);
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static List<Long> miniMaxSum(final List<Integer> array) {
            long sum = array.stream().mapToLong(Integer::longValue).reduce(0L, Long::sum);
            long minSum = sum - array.getLast();
            long maxSum = sum - array.getFirst();
            return Arrays.asList(minSum, maxSum);
        }
}
