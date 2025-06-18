// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] chocolateSquares = ReadNumbers();
        int[] dayMonth = ReadNumbers();
        Console.WriteLine(Birthday(chocolateSquares, dayMonth));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int Birthday(int[] chocolateSquares, int[] dayMonth)
    {
        int day = dayMonth[0];
        int month = dayMonth[1];

        if (month > chocolateSquares.Length)
            return 0;

        int sum = chocolateSquares.Take(month).Sum();
        int waysBarCanBeDivided = sum == day ? 1 : 0;

        foreach (var i in Enumerable.Range(month, chocolateSquares.Length - month))
        {
            sum += chocolateSquares[i] - chocolateSquares[i - month];
            if (sum == day)
                waysBarCanBeDivided++;
        }

        return waysBarCanBeDivided;
    }
}
