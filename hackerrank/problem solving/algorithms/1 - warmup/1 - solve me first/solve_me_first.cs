// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n1 = int.Parse(Console.ReadLine());
        int n2 = int.Parse(Console.ReadLine());
        Console.WriteLine(SolveMeFirst(n1, n2));
    }

    private static int SolveMeFirst(int n1, int n2)
    {
        return n1 + n2;
    }
}
