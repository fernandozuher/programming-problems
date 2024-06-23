// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        List<Integer> array = readIntArray();
        System.out.println(kangaroo(array));
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).collect(toList());
        }

        private static String kangaroo(final List<Integer> array) {
            int x1 = array.get(0);
            int v1 = array.get(1);
            int x2 = array.get(2);
            int v2 = array.get(3);

            if (v2 >= v1)
                return "NO";
            for (; x1 < x2; x1 += v1, x2 += v2);
            return x1 == x2 ? "YES" : "NO";
        }
}
