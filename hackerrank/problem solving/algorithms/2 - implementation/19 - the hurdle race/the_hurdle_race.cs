// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int maxJump = ReadNumbers()[1];
        int[] hurdles = ReadNumbers();
        Console.WriteLine(HurdleRace(hurdles, maxJump));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int HurdleRace(int[] hurdles, int maxJump)
    {
        return Math.Max(0, hurdles.Max() - maxJump);
    }
}
