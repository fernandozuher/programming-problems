// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] numbers = ReadNumbers();
        double[] ratios = PlusMinus(numbers);
        PrintRatios(ratios);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }

    private static double[] PlusMinus(int[] numbers)
    {
        int positive = 0;
        int negative = 0;
        int zero = 0;

        foreach (int x in numbers)
            if (x > 0)
                ++positive;
            else if (x < 0)
                ++negative;
            else
                ++zero;

        double n = numbers.Length;
        return [positive / n, negative / n, zero / n];
    }

    private static void PrintRatios(double[] ratios)
    {
        foreach (double ratio in ratios)
            Console.WriteLine(ratio.ToString("F6"));
    }
}
