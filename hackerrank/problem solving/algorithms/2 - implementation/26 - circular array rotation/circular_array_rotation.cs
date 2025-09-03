// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] line = ReadNumbers();
        int nRotation = line[1];
        int nQueries = line[2];
        int[] arr = ReadNumbers();
        int[] queries = Enumerable.Range(0, nQueries).Select(_ => int.Parse(Console.ReadLine()!)).ToArray();
        PrintQueries(arr, queries, nRotation);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray();
    }

    private static void PrintQueries(int[] arr, int[] queries, int nRotation)
    {
        int n = arr.Length;
        int r = nRotation % n;
        foreach (var q in queries)
        {
            int idx = (q + n - r) % n;
            Console.WriteLine(arr[idx]);
        }
    }
}
