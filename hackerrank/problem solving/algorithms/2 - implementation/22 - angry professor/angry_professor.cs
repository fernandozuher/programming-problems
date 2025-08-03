// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = ReadNumbers()[0];

        Enumerable.Range(0, n).Select<int, bool>(_ =>
        {
            int threshold = ReadNumbers()[1];
            int[] arrivalTimes = ReadNumbers();
            return AngryProfessor(arrivalTimes, threshold);
        })
        .ToList()
        .ForEach(cancelled => Console.WriteLine(cancelled ? "YES" : "NO"));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static bool AngryProfessor(int[] arrivalTimes, int threshold)
    {
        int onTime = arrivalTimes.Count(t => t <= 0);
        return onTime < threshold;
    }
}
