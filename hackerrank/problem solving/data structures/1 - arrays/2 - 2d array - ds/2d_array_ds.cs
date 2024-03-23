// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public static void Main() {
        var matrix = new List<List<int>>();
        for (int n = 6; n-- > 0;)
            matrix.Add(Console.ReadLine().Split().Select(int.Parse).ToList());
        Console.WriteLine(MaxHourglassSum(matrix));
    }

        public static int MaxHourglassSum(List<List<int>> matrix) {
            int maxSum = Int32.MinValue;

            for (int i = 1, rowsCols = 4; i <= rowsCols; ++i)
                for (int j = 1; j <= rowsCols; ++j)
                {
                    int currentSum = HourglassSum(matrix, i, j);
                    maxSum = Math.Max(maxSum, currentSum);
                }

            return maxSum;
        }

            public static int HourglassSum(List<List<int>> matrix, int i, int j)
            {
                int subrow1FirstIndex = i - 1;
                int subrow3FirstIndex = i + 1;
                int firstColIndex = j - 1;
                const int n = 3;

                int subrow1Sum = matrix[subrow1FirstIndex].GetRange(firstColIndex, n).Sum();
                int subrow3Sum = matrix[subrow3FirstIndex].GetRange(firstColIndex, n).Sum();

                return subrow1Sum + matrix[i][j] + subrow3Sum;
            }
}
