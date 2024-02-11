// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

using System;
using System.Numerics;

public class Solution
{
    public static void Main()
    {
        int number = int.Parse(Console.ReadLine());
        BigInteger factorial = _calculateFactorialOf(number);
        Console.WriteLine(factorial);
    }

        private static BigInteger _calculateFactorialOf(int number)
        {
            BigInteger factorial = BigInteger.One;
            for (int currentNumber = 2; currentNumber <= number; ++currentNumber)
                factorial = BigInteger.Multiply(factorial, new BigInteger(currentNumber));
            return factorial;
        }
}
