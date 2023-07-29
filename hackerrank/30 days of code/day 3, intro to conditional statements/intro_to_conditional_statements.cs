// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        if (n % 2 == 1 || n >= 6 && n <= 20)
            Console.WriteLine("Weird");
        else
            Console.WriteLine("Not Weird");
    }
}
