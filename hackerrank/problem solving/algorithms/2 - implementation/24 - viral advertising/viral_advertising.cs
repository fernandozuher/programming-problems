// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int days = int.Parse(Console.ReadLine()!);
        Console.WriteLine(ViralAdvertising(days));
    }

    private static int ViralAdvertising(int days)
    {
        int shared = 5;
        return Enumerable.Range(0, days).Sum(_ =>
        {
            int liked = shared / 2;
            shared = liked * 3;
            return liked;
        });
    }
}
