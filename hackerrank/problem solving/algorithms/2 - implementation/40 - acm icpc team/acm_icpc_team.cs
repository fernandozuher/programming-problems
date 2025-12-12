// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

using System.Numerics;

int attendees = ReadNumbers()[0];
List<BigInteger> binaries = ReadBinaries(attendees);
AcmTeam(binaries).ForEach(x => Console.WriteLine(x));

int[] ReadNumbers() {
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

List<BigInteger> ReadBinaries(int n)
{
    return Enumerable.Range(0, n)
        .Select(_ => Console.ReadLine()!.Aggregate(new BigInteger(), (b, c) => b * 2 + c - '0'))
        .ToList();
}

List<BigInteger> AcmTeam(List<BigInteger> binaries)
{
    int maxSubjects = 0;
    int teamsWithMax = 0;
    int i = 0;

    foreach (var a in binaries.SkipLast(1))
    {
        foreach (var b in binaries.Skip(++i))
        {
            int knownSubjects = CountSubjectsKnownBy2Teams(a, b);

            if (knownSubjects > maxSubjects)
            {
                maxSubjects = knownSubjects;
                teamsWithMax = 1;
            }
            else if (knownSubjects == maxSubjects)
                teamsWithMax++;
        }
    }

    return [maxSubjects, teamsWithMax];
}

int CountSubjectsKnownBy2Teams(BigInteger a, BigInteger b)
{
    return (int)BigInteger.PopCount(a | b);
}
