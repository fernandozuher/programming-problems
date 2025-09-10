// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

using System.Numerics;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()!);
        Console.WriteLine(Factorial(n));
    }

    private static BigInteger Factorial(int n)
    {
        return Enumerable.Range(1, n).Aggregate(BigInteger.One, (acc, x) => acc * x);
    }
}
