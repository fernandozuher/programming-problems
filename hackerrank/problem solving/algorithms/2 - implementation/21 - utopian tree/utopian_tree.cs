// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()!);
        Array.ForEach(UtopianTree(ReadNumbers(n)), Console.WriteLine);
    }

    private static int[] ReadNumbers(int n)
    {
        return Enumerable.Range(0, n).Select(_ => int.Parse(Console.ReadLine()!)).ToArray();
    }

    private static int[] UtopianTree(int[] testCases)
    {
        return testCases.Select(CalculateHeight).ToArray();
    }

    private static int CalculateHeight(int cycles)
    {
        return Enumerable.Range(1, cycles)
            .Aggregate(1, (height, cycle) =>
            IsCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1
        );
    }

    private static bool IsCycleHappeningDuringSpring(int cycle)
    {
        return (cycle & 1) == 1;
    }
}
