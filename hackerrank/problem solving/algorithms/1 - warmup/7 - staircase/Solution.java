// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// From Java 16

import java.util.Scanner;
import java.util.stream.IntStream;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        staircase(n);
    }

        public static void staircase(int n) {
            IntStream.range(1, n + 1).forEach(i -> {
                IntStream.range(0, n - i).forEach(_ -> System.out.print(" "));
                IntStream.range(0, i).forEach(_ -> System.out.print("#"));
                System.out.println();
            });
        }
}
