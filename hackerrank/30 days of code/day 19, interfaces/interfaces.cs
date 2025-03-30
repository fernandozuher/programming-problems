// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

using static System.Console;

public static class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        var calc = new Calculator();
        WriteLine("I implemented: AdvancedArithmetic\n" + calc.DivisorSum(n));
    }
}

public interface AdvancedArithmetic
{
    int DivisorSum(int n);
}

public class Calculator : AdvancedArithmetic
{
    public int DivisorSum(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n / 2; ++i)
            if (IsDivisibleBy(n, i))
                sum += i;
        return sum + n;
    }

    private static bool IsDivisibleBy(int a, int b)
    {
        return a % b == 0;
    }
}
