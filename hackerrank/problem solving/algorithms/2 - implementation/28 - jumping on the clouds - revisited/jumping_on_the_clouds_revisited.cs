// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int jumpLength = ReadNumbers()[1];
        int[] arr = ReadNumbers();
        Console.WriteLine(JumpingOnTheClouds(arr, jumpLength));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int JumpingOnTheClouds(int[] clouds, int jumpLength)
    {
        int energy = 100;
        int cloudIndex = 0;

        do
        {
            energy -= clouds[cloudIndex] == 0 ? 1 : 3;
            cloudIndex = (cloudIndex + jumpLength) % clouds.Length;
        } while (cloudIndex != 0);

        return energy;
    }
}
