// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

using System.Numerics;

int n = int.Parse(Console.ReadLine()!);
Console.WriteLine(Factorial(n));

BigInteger Factorial(int n)
{
    return Enumerable.Range(1, n).Select(x => (BigInteger)x).Aggregate(BigInteger.Multiply);
}
