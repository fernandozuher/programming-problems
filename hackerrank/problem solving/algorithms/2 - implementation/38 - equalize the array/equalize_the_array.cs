// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

public class EqualizeTheArray
{
    public static void Main()
    {
        Console.ReadLine();
        Console.WriteLine(EqualizeArray(ReadNumbers()));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int EqualizeArray(int[] arr)
    {
        var counter = Counter(arr);
        return arr.Length - counter.Values.Max();
    }

    private static Dictionary<int, int> Counter(int[] arr)
    {
        return arr.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
    }
}
