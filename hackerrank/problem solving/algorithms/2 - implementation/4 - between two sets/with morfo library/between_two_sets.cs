// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

using Morfo.IO;
using Morfo.Math;

Reader.SkipInputLn();
int[] a = Reader.ReadLn<int, int[]>();
int[] b = Reader.ReadLn<int, int[]>();
Console.WriteLine(BetweenTwoSets(a, b));

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
int BetweenTwoSets(int[] a, int[] b)
{
    int lcmOfA = a.Lcm();
    int gcdOfB = b.Gcd();

    int count = 0;
    for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
        if (gcdOfB % i == 0)
            count++;
    return count;
}
