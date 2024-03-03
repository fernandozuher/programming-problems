// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);

        List<List<Integer>> matrix = new ArrayList<List<Integer>>();
        final int n = 6;
        for (int i = 0; i < n; ++i)
            matrix.add(Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList()));

        System.out.println(maxHourglassSum(matrix));
    }

        public static int maxHourglassSum(final List<List<Integer>> matrix) {
            int maxSum = Integer.MIN_VALUE;

            for (int i = 1, rowsCols = 4; i <= rowsCols; ++i)
                for (int j = 1; j <= rowsCols; ++j) {
                    int currentSum = hourglassSum(matrix, i, j);
                    maxSum = Math.max(maxSum, currentSum);
                }

            return maxSum;
        }

            public static int hourglassSum(final List<List<Integer>> matrix, final int i, final int j) {
                return matrix.get(i - 1).get(j - 1) + matrix.get(i - 1).get(j) + matrix.get(i - 1).get(j + 1)
                       + matrix.get(i).get(j) +
                       matrix.get(i + 1).get(j - 1) + matrix.get(i + 1).get(j) + matrix.get(i + 1).get(j + 1);
            }
}
