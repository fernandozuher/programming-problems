// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int num1 = int.Parse(Console.ReadLine());
        int num2 = int.Parse(Console.ReadLine());
        Console.WriteLine(_solveMeFirst(num1, num2));
    }

        private static int _solveMeFirst(int a, int b)
        {
            return a + b;
        }
}
