// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] arr = ReadNumbers();
        Array.Sort(arr);
        CutTheSticks(arr).ForEach(Console.WriteLine);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static List<int> CutTheSticks(int[] arr)
    {
        var res = new List<int>();
        for (int i = 0, n = arr.Length; i < n;)
        {
            res.Add(n - i);
            for (int shortest = arr[i]; i < n && arr[i] == shortest; i++);
        }
        return res;
    }
}
