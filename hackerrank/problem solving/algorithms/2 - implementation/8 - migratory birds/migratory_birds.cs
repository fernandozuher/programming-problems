// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] birds = ReadNumbers();
        Console.WriteLine(FindMostSpottedBird(birds));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int FindMostSpottedBird(int[] birds)
    {
        return birds.GroupBy(bird => bird)
                    .OrderByDescending(group => group.Count())
                    .ThenBy(group => group.Key)
                    .First()
                    .Key;
    }
}
