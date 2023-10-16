// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        for (int n = int.Parse(Console.ReadLine()); n-- > 0;)
        {
            int number = int.Parse(Console.ReadLine());

            if (number == 1)
            {
                Console.WriteLine("Not prime");
                continue;
            }

            int i = 2, limit = (int) (Math.Sqrt(number));
            for (; i <= limit; ++i)
                if (number % i == 0)
                {
                    Console.WriteLine("Not prime");
                    break;
                }

            if (i > limit)
                Console.WriteLine("Prime");
        }
    }
}
