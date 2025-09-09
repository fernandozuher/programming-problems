// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            IntStream.range(0, n).map(_ -> findDigits(scan.nextInt())).forEach(System.out::println);
        }
    }

    private static int findDigits(int n) {
        return (int) String.valueOf(n).chars().map(c -> c - '0').filter(d -> d != 0 && n % d == 0).count();
    }
}
