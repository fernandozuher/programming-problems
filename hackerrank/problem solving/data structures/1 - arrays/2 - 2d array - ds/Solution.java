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
                int subrow1FirstIndex = i - 1;
                int subrow3FirstIndex = i + 1;
                int firstColIndex = j - 1;
                final int end = firstColIndex + 3;

                int subrow1Sum = matrix.get(subrow1FirstIndex)
                                 .subList(firstColIndex, end)
                                 .stream()
                                 .mapToInt(Integer::intValue)
                                 .sum();

                int subrow3Sum = matrix.get(subrow3FirstIndex)
                                 .subList(firstColIndex, end)
                                 .stream()
                                 .mapToInt(Integer::intValue)
                                 .sum();

                return subrow1Sum + matrix.get(i).get(j) + subrow3Sum;
            }
}
