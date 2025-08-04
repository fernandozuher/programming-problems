// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        var numbers = ReadNumbers();
        int startDay = numbers[0];
        int endDay = numbers[1];
        int divisor = numbers[2];
        Console.WriteLine(BeautifulDays(startDay, endDay, divisor));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int BeautifulDays(int startDay, int endDay, int divisor)
    {
        return Enumerable.Range(startDay, endDay - startDay + 1).Count(day => IsDayBeautiful(day, divisor));
    }

    private static bool IsDayBeautiful(int day, int divisor)
    {
        return Math.Abs(day - ReverseNumber(day)) % divisor == 0;
    }

    private static int ReverseNumber(int number)
    {
        return int.Parse(new string(number.ToString().Reverse().ToArray()));
    }
}
