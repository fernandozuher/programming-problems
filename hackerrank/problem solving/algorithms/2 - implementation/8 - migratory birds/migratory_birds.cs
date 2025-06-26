// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] birdCounts = ReadNumbers();
        Console.WriteLine(FindMostSpottedBird(birdCounts));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int FindMostSpottedBird(int[] birdCounts)
    {
        return birdCounts.GroupBy(bird => bird)
                    .OrderByDescending(group => group.Count())
                    .ThenBy(group => group.Key)
                    .First()
                    .Key;
    }
}
