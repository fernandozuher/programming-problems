// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

using System;
using System.Numerics;

public class Solution
{
    public static void Main()
    {
        int number = _ReadANumber();
        BigInteger FACTORIAL = _CalculateFactorialOf(number);
        Console.WriteLine(FACTORIAL);
    }

        private static int _ReadANumber()
        {
            return int.Parse(Console.ReadLine());
        }

        private static BigInteger _CalculateFactorialOf(int number)
        {
            BigInteger factorial = BigInteger.One;
            for (int i = 2; i <= number; i++)
                factorial = BigInteger.Multiply(factorial, new BigInteger(i));
            return factorial;
        }
}
