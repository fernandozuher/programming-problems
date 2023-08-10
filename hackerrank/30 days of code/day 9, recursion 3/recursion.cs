// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(_factorial(n));
    }

        private static int _factorial(int n)
        {
            return n == 1 ? 1 : n * _factorial(n - 1);
        }
}
