// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// Java 22

import java.util.Scanner;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            System.out.println(aVeryBigSum(scan, n));
        }
    }

    private static long aVeryBigSum(Scanner scan, int n) {
        return IntStream.range(0, n)
                .mapToLong(_ -> scan.nextLong())
                .sum();
    }
}
