// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        WriteLine(Factorial(n));
    }

    private static int Factorial(int n)
    {
        return n == 1 ? 1 : n * Factorial(n - 1);
    }
}
