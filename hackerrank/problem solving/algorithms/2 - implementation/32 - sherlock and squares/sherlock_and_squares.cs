// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = ReadNumbers()[0];
        for (int i = 0; i < n; i++)
        {
            var range = ReadNumbers();
            int a = range[0];
            int b = range[1];
            Console.WriteLine(Squares(a, b));
        }
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int Squares(int startNum, int endNum)
    {
        int maxSquare = (int)Math.Floor(Math.Sqrt(endNum));
        int minSquare = (int)Math.Ceiling(Math.Sqrt(startNum));
        return maxSquare - minSquare + 1;
    }
}
