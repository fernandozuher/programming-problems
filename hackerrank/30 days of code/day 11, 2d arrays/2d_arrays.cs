// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

using System;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int[ , ] matrix = _readMatrix();
        int maxSum = _calculateMaxSum(matrix);
        Console.WriteLine(maxSum);
    }

        private static int[ , ] _readMatrix()
        {
            const int nRowsColumns = 6;
            int[ , ] matrix = new int[nRowsColumns, nRowsColumns];

            for (int i = 0; i < nRowsColumns; i++)
            {
                int[] row = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < nRowsColumns; j++)
                    matrix[i, j] = row[j];
            }

            return matrix;
        }

        private static int _calculateMaxSum(int[ , ] matrix)
        {
            int maxSum = int.MinValue;

            for (int i = 1, beforeRowsColumnsLimit = 5; i < beforeRowsColumnsLimit; i++)
                for (int j = 1; j < beforeRowsColumnsLimit; j++)
                    maxSum = Math.Max(maxSum, _sumAround(matrix, i, j));

            return maxSum;
        }

            private static int _sumAround(int[ , ] matrix, int i, int j)
            {
                return matrix[i - 1, j - 1] + matrix[i - 1, j] + matrix[i - 1, j + 1] +
                       matrix[i, j] +
                       matrix[i + 1, j - 1] + matrix[i + 1, j] + matrix[i + 1, j + 1];
            }
}
