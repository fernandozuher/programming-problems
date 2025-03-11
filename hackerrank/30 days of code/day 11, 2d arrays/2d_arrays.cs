// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

using static System.Console;

class Solution
{
    public static void Main()
    {
        int[,] matrix = ReadMatrix();
        WriteLine(CalculateMaxSum(matrix));
    }

    private static int[,] ReadMatrix()
    {
        const int nRowsColumns = 6;
        var matrix = new int[nRowsColumns, nRowsColumns];

        for (int i = 0; i < nRowsColumns; i++)
        {
            int[] row = [.. ReadLine().Split().Select(int.Parse)];
            for (int j = 0; j < nRowsColumns; j++)
                matrix[i, j] = row[j];
        }

        return matrix;
    }

    private static int CalculateMaxSum(int[,] matrix)
    {
        int maxSum = int.MinValue;

        for (int i = 1, beforeRowsColumnsLimit = 5; i < beforeRowsColumnsLimit; i++)
            for (int j = 1; j < beforeRowsColumnsLimit; j++)
                maxSum = Math.Max(maxSum, SumAround(matrix, i, j));

        return maxSum;
    }

    private static int SumAround(int[,] matrix, int i, int j)
    {
        return matrix[i - 1, j - 1] + matrix[i - 1, j] + matrix[i - 1, j + 1] +
               matrix[i, j] +
               matrix[i + 1, j - 1] + matrix[i + 1, j] + matrix[i + 1, j + 1];
    }
}
