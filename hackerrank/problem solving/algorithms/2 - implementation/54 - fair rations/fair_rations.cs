// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

Console.ReadLine();
int[] peopleLoafCounts = ReadNumbers();
int minLoaves = MinLoavesToSatisfyRules(peopleLoafCounts);
Console.WriteLine(minLoaves == -1 ? "NO" : minLoaves);

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int MinLoavesToSatisfyRules(int[] peopleLoafCounts)
{
    int loavesGiven = 0;
    int counts = peopleLoafCounts[0];

    foreach (var x in peopleLoafCounts.Skip(1))
    {
        if (IsOdd(counts))
        {
            loavesGiven += 2;
            counts = x + 1;
        }
        else
        {
            counts = x;
        }
    }

    return IsOdd(counts) ? -1 : loavesGiven;
}

bool IsOdd(int n)
{
    return n % 2 == 1;
}
