// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int nTests = int.Parse(ReadLine());
        ProcessPrimeTests(nTests);
    }

    private static void ProcessPrimeTests(int nTests)
    {
        while (nTests-- > 0)
        {
            int n = int.Parse(ReadLine());
            WriteLine(IsPrime(n) ? "Prime" : "Not prime");
        }
    }

    private static bool IsPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int divisor = 3, limit = (int)Math.Sqrt(n); divisor <= limit; divisor += 2)
            if (n % divisor == 0)
                return false;
        return true;
    }
}
