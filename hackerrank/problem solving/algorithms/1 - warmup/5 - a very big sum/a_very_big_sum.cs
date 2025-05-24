// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        long[] numbers = ReadNumbers();
        Console.WriteLine(AVeryBigSum(numbers));
    }

    private static long[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(long.Parse).ToArray();
    }

    private static long AVeryBigSum(long[] numbers)
    {
        return numbers.Sum();
    }
}
