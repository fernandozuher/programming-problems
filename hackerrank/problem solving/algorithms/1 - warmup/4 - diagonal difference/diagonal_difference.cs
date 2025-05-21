// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(DiagonalDifference(n));
    }

    private static int DiagonalDifference(int n)
    {
        int primarySum = 0, secondarySum = 0;

        for (int i = 0; i < n; i++)
        {
            int[] numbers = ReadNumbers();
            primarySum += numbers[i];
            secondarySum += numbers[n - i - 1];
        }

        return Math.Abs(primarySum - secondarySum);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
}
