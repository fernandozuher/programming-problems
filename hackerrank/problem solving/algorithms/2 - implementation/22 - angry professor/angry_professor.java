// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();

            IntStream.range(0, n).mapToObj(_ -> {
                int _ = scan.nextInt();
                int threshold = scan.nextInt();
                scan.nextLine();
                int[] arrivalTimes = readNumbers(scan);
                return angryProfessor(arrivalTimes, threshold);
            }).forEach(cancelled -> System.out.println(cancelled ? "YES" : "NO"));
        }
    }

    private static int[] readNumbers(Scanner scan) {
        return Stream.of(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static boolean angryProfessor(int[] arrivalTimes, int threshold) {
        long count = Arrays.stream(arrivalTimes).filter(t -> t <= 0).count();
        return count < threshold;
    }
}
