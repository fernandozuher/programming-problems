// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] numbers = ReadNumbers();
        var (minSum, maxSum) = CalcMinMaxSum(numbers);
        Console.WriteLine("{0} {1}", minSum, maxSum);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }

    private static (long, long) CalcMinMaxSum(int[] numbers)
    {
        long sum, min, max;
        sum = min = max = numbers[0];

        foreach (var x in numbers.Skip(1))
        {
            sum += x;
            min = Math.Min(x, min);
            max = Math.Max(x, max);
        }

        return (sum - max, sum - min);
    }
}
