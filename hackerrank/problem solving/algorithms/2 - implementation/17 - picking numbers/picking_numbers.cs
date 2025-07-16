// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        Console.WriteLine(PickingNumbers(ReadNumbers()));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int PickingNumbers(int[] numbers)
    {
        Dictionary<int, int> counter = numbers.GroupBy(num => num)
                                              .ToDictionary(g => g.Key, g => g.Count());

        int maxLen = 0;
        foreach (int num in counter.Keys)
        {
            int current = counter[num] + (counter.ContainsKey(num + 1) ? counter[num + 1] : 0);
            maxLen = Math.Max(maxLen, current);
        }

        return maxLen;
    }
}
