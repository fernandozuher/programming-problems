// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] line = ReadNumbers();
        int beautifulDifference = line[1];
        int[] arr = ReadNumbers();
        Console.WriteLine(FindBeautifulTriplets(arr, beautifulDifference));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int FindBeautifulTriplets(int[] arr, int beautifulDifference)
    {
        var values = new HashSet<int>(arr);
        return arr.Count(x => values.Contains(x + beautifulDifference) && values.Contains(x + 2 * beautifulDifference));
    }
}
