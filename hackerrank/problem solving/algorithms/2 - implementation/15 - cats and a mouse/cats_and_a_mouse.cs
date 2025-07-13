// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

public class Solution
{
    public static void Main()
    {
        int n = ReadNumbers()[0];
        Enumerable.Range(0, n)
            .Select(_ => FindNearestCatOrNot(ReadNumbers()))
            .ToList()
            .ForEach(Console.WriteLine);
    }
    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static string FindNearestCatOrNot(int[] positions)
    {
        int catA = positions[0];
        int catB = positions[1];
        int mouse = positions[2];
        int catAFromMouse = Math.Abs(catA - mouse);
        int catBFromMouse = Math.Abs(catB - mouse);

        if (catAFromMouse < catBFromMouse)
            return "Cat A";
        if (catAFromMouse > catBFromMouse)
            return "Cat B";
        return "Mouse C";
    }
}
