// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        WriteLine(DiagonalDifference(n));
    }

        static int DiagonalDifference(int n)
        {
            int primaryDiagonal = 0, secondaryDiagonal = 0;

            for (int i = 0; i < n; ++i)
            {
                List<int> line = ReadIntArray();
                primaryDiagonal += line[i];
                secondaryDiagonal += line[n - i - 1];
            }

            return Math.Abs(primaryDiagonal - secondaryDiagonal);
        }

            static List<int> ReadIntArray()
            {
                return ReadLine().Split().Select(int.Parse).ToList();
            }
}
