// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Staircase(n);
    }

    private static void Staircase(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            var spaces = new string(' ', n - i);
            var hashes = new string('#', i);
            Console.WriteLine(spaces + hashes);
        }
    }
}
