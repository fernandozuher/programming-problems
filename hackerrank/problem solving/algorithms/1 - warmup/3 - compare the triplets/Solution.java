// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// From Java 16

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        final int n = 3;
        List<Integer> array1 = readIntArray(n);
        List<Integer> array2 = readIntArray(n);
        List<Integer> result = compareTriplets(array1, array2);
        System.out.print(result.get(0) + " " + result.get(1));
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).toList();
        }

        public static List<Integer> compareTriplets(List<Integer> array1, List<Integer> array2) {
            int player1 = 0, player2 = 0;

            for (int i = 0; i < array1.size(); ++i) {
                if (array1.get(i) > array2.get(i))
                    ++player1;
                else if (array2.get(i) > array1.get(i))
                    ++player2;
            }

            return Arrays.asList(player1, player2);
        }
}
