// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// Java 25

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] peopleLoafCounts = ReadNumbers();
        int minLoaves = MinLoavesToSatisfyRules(peopleLoafCounts);
        Console.WriteLine(minLoaves == -1 ? "NO" : minLoaves);
    }

    private static int[] ReadNumbers()
    {
        return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
    }

    private static int MinLoavesToSatisfyRules(int[] peopleLoafCounts)
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

        if (IsOdd(counts))
        {
            return -1;
        }
        return loavesGiven;
    }

    private static bool IsOdd(int n)
    {
        return n % 2 == 1;
    }
}
