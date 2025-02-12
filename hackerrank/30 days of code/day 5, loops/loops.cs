// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        foreach (int i in Enumerable.Range(1, 10))
            WriteLine("{0} x {1} = {2}", n, i, n * i);
    }
}
