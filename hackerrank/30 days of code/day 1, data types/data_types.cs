// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        const int i = 4;
        const double d = 4.0;
        const string s = "HackerRank ";

        int i2 = int.Parse(Console.ReadLine());
        double d2 = double.Parse(Console.ReadLine());
        string s2 = Console.ReadLine();

        Console.WriteLine(i + i2);
        Console.WriteLine("{0:0.0}", d + d2);
        Console.WriteLine(s + s2);
    }
}
