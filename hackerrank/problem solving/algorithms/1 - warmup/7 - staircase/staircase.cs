// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        _staircase(n);
    }

        private static void _staircase(int n)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j < n - i; ++j)
                    Console.Write(" ");
                for (int k = 0; k < i; ++k)
                    Console.Write("#");
                Console.Write("\n");
            }
        }
}
