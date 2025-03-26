// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

using static System.Console;

public static class Solution
{
    public static void Main()
    {
        for (int nTests = int.Parse(ReadLine() ?? "0"); nTests-- > 0;)
        {
            var (n, p) = ReadInput();
            Power(n, p);
        }
    }

    private static (int, int) ReadInput()
    {
        var inputs = ReadLine().Split().Select(int.Parse).ToArray();
        int n = inputs[0];
        int p = inputs[1];
        return (n, p);
    }

    private static void Power(int n, int p)
    {
        try
        {
            WriteLine(Calculator.Power(n, p));
        }
        catch (IOException e)
        {
            WriteLine(e.Message);
        }
    }
}

public static class Calculator
{
    public static int Power(int n, int p)
    {
        if (n < 0 || p < 0)
            throw new IOException("n and p should be non-negative");
        return (int)Math.Pow(n, p);
    }
}
