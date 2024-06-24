// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// From Java 21

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        final int n = 4;
        List<Integer> array = readIntArray(n);
        System.out.println(kangaroo(array));
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static String kangaroo(final List<Integer> array) {
            int x1 = array.getFirst();
            int v1 = array.get(1);
            int x2 = array.get(2);
            int v2 = array.getLast();

            if (v2 >= v1) return "NO";
            for (; x1 < x2; x1 += v1, x2 += v2);
            return x1 == x2 ? "YES" : "NO";
        }
}
