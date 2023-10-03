// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

using System;
using System.IO;

public class Solution
{
    public static void Main()
    {
        Calculator calc = new Calculator();

        for (int nTests = int.Parse(Console.ReadLine()); nTests-- > 0;)
        {
            string[] s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int p = int.Parse(s[1]);

            try
            {
                Console.WriteLine(calc.Power(n, p));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}

    public class Calculator
    {
        public int Power(int n, int p)
        {
            if (n < 0 || p < 0)
                throw new IOException("n and p should be non-negative");
            return (int) Math.Pow(n, p);
        }
    }
