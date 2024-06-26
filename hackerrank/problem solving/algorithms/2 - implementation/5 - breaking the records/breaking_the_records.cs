// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        ReadIntArray();
        List<int> array = ReadIntArray();
        var (mostPointsRecords, leastPointsRecords) = BreakingRecords(array);
        Console.WriteLine("{0} {1}", mostPointsRecords, leastPointsRecords);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        static (int, int) BreakingRecords(List<int> scores)
        {
            int mostPoints = scores.First(), leastPoints = scores.First();
            int breakingMostPointsRecords = 0, breakingLeastPointsRecords = 0;

            foreach (var score in scores)
                if (score > mostPoints)
                {
                    mostPoints = score;
                    ++breakingMostPointsRecords;
                }
                else if (score < leastPoints)
                {
                    leastPoints = score;
                    ++breakingLeastPointsRecords;
                }

            return (breakingMostPointsRecords, breakingLeastPointsRecords);
        }
}