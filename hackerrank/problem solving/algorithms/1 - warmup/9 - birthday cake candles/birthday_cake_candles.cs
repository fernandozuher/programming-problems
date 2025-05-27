// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] candles = ReadNumbers();
        Console.WriteLine(BirthdayCakeCandles(candles));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }

    private static int BirthdayCakeCandles(int[] candles)
    {
        int max = candles.Max();
        return candles.Count(x => x == max);
    }
}
