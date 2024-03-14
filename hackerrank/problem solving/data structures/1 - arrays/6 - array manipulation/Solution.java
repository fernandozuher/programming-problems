// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        int nQueries = scan.nextInt();
        System.out.println(arrayManipulation(n, nQueries));
    }

        public static long arrayManipulation(final int n, int nQueries) {
            int size = n + 2; // 1-indexed array + range-end
            var array = new ArrayList<Integer>(Collections.nCopies(size, 0));

            while (nQueries-- > 0) {
                int b = scan.nextInt();
                int e = scan.nextInt();
                int summand = scan.nextInt();
                array.set(b, array.get(b) + summand);
                array.set(e + 1, array.get(e + 1) - summand);
            }

            long sum = 0, max = 0;
            for (final int x : array) {
                if (x == 0)
                    continue;
                sum += x;
                max = Math.max(max, sum);
            }

            return max;
        }
}
