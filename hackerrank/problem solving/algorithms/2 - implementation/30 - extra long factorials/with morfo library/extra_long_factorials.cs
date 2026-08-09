// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

using System.Numerics;
using Morfo.IO;

int n = Reader.Read<int>();
Console.WriteLine(Factorial(n));

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
BigInteger Factorial(int n) => Enumerable.Range(1, n).Select(x => (BigInteger)x).Aggregate(BigInteger.Multiply);
