// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        Dictionary<int, int> sockCounts = ReadNumbersIntoMap();
        Console.WriteLine(SockMerchant(sockCounts));
    }

    private static Dictionary<int, int> ReadNumbersIntoMap()
    {
        var numberCounts = new Dictionary<int, int>();
        foreach (var x in Console.ReadLine()!.Split().Select(int.Parse))
        {
            numberCounts.TryGetValue(x, out int count);
            numberCounts[x] = ++count;
        }
        return numberCounts;
    }

    private static int SockMerchant(Dictionary<int, int> sockCounts) => sockCounts.Values.Sum(count => count / 2);
}
