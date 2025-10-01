// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        Console.WriteLine(MinimumNumberOfJumps(ReadNumbers()));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int MinimumNumberOfJumps(int[] clouds)
    {
        int jumps = 0;
        for (int i = 0, n = clouds.Length - 1; i < n; i += NextJump(i, clouds))
            jumps++;
        return jumps;
    }

    private static int NextJump(int index, int[] clouds)
    {
        bool isNextSecondCloudCumulus = false;
        if (index + 2 < clouds.Length)
            isNextSecondCloudCumulus = clouds[index + 2] == 0;
        return isNextSecondCloudCumulus ? 2 : 1;
    }
}
