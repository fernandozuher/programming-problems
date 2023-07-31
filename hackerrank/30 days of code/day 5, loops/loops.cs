// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        for (int i = 1, n = int.Parse(Console.ReadLine()); i <= 10; ++i)
            Console.WriteLine("{0} x {1} = {2}", n, i, n * i);
    }
}
