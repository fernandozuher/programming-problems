// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<List<int>> matrix = _readMatrix(n);
        Console.WriteLine("{0}", _diagonalDifference(matrix));
    }

        private static List<List<int>> _readMatrix(int n)
        {
            var matrix = new List<List<int>>();
            while (n-- > 0)
                matrix.Add(Console.ReadLine().Split(" ").Select(int.Parse).ToList());
            return matrix;
        }

        private static int _diagonalDifference(List<List<int>> matrix)
        {
            int primaryDiagonal = 0, secondaryDiagonal = 0;

            for (int i = 0, j = matrix.Count - 1, n = matrix.Count; i < n; ++i, --j)
            {
                primaryDiagonal += matrix[j][j];
                secondaryDiagonal += matrix[j][i];
            }

            return Math.Abs(primaryDiagonal - secondaryDiagonal);
        }
}
