// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] numbers = ReadNumbers();
        int k = numbers[1];
        numbers = ReadNumbers();
        Console.WriteLine(DivisibleSumPairs(numbers, k));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int DivisibleSumPairs(int[] numbers, int k)
    {
        int[] frequency = InitRemainderFrequency(numbers, k);
        return CountPairsWithRemainder0(frequency) + CountComplementaryRemainderPairs(frequency)
               + CountPairsWithRemainderKHalf(frequency);
    }

    private static int[] InitRemainderFrequency(int[] numbers, int k)
    {
        int[] frequency = new int[k];
        foreach (int x in numbers)
            frequency[x % k]++;
        return frequency;
    }

    private static int CountPairsWithRemainder0(int[] frequency) => PairCount(frequency[0]);

    private static int PairCount(int n) => n * (n - 1) / 2;

    private static int CountComplementaryRemainderPairs(int[] frequency)
    {
        int k = frequency.Length;
        return Enumerable.Range(1, (k + 1) / 2 - 1).Sum(i => frequency[i] * frequency[k - i]);
    }

    private static int CountPairsWithRemainderKHalf(int[] frequency)
    {
        int k = frequency.Length;
        return k % 2 == 0 ? PairCount(frequency[k / 2]) : 0;
    }
}
