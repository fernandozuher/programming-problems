// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] scores = ReadNumbers();
        var (mostRecordBreaks, leastRecordBreaks) = BreakingRecords(scores);
        Console.WriteLine($"{mostRecordBreaks} {leastRecordBreaks}");
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static (int, int) BreakingRecords(int[] scores)
    {
        int mostPoints = scores[0], leastPoints = scores[0];
        int mostRecordBreaks = 0, leastRecordBreaks = 0;

        foreach (int score in scores.Skip(1))
            if (score > mostPoints)
            {
                mostPoints = score;
                mostRecordBreaks++;
            }
            else if (score < leastPoints)
            {
                leastPoints = score;
                leastRecordBreaks++;
            }

        return (mostRecordBreaks, leastRecordBreaks);
    }
}
