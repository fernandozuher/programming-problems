// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

using System.Numerics;

class Solution
{
    public static void Main()
    {
        int[] arr = ReadNumbers();
        int attendees = arr[0];
        List<BigInteger> binaries = ReadBinaries(attendees);
        AcmTeam(binaries).ForEach(x => Console.WriteLine(x));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static List<BigInteger> ReadBinaries(int n)
    {
        return Enumerable.Range(0, n)
            .Select(_ => Console.ReadLine()!.Aggregate(new BigInteger(), (b, c) => b * 2 + c - '0'))
            .ToList();
    }

    private static List<BigInteger> AcmTeam(List<BigInteger> binaries)
    {
        int maxSubjects = 0;
        int teamsWithMax = 0;
        int i = 0;

        foreach (var b1 in binaries.SkipLast(1))
            foreach (var b2 in binaries.Skip(++i))
            {
                int knownSubjects = CountSubjectsKnownBy2Teams(b1, b2);

                if (knownSubjects > maxSubjects)
                {
                    maxSubjects = knownSubjects;
                    teamsWithMax = 1;
                }
                else if (knownSubjects == maxSubjects)
                    teamsWithMax++;
            }

        return [maxSubjects, teamsWithMax];
    }

    private static int CountSubjectsKnownBy2Teams(BigInteger a, BigInteger b)
    {
        return (int)BigInteger.PopCount(a | b);
    }
}