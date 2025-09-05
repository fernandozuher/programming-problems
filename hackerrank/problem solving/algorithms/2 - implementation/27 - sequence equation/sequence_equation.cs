// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] arr = ReadNumbers();
        SequenceEquation(arr).ForEach(Console.WriteLine);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static List<int> SequenceEquation(int[] arr)
    {
        int[] valuesToIndex = new int[arr.Length];
        int i = 0;
        foreach (int val in arr)
        {
            valuesToIndex[val - 1] = i++;
        }
        return valuesToIndex.Select(val => valuesToIndex[val] + 1).ToList();
    }
}
