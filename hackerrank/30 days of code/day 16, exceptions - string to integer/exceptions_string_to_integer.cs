// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        string s = Console.ReadLine();

        try {
            Console.WriteLine(int.Parse(s));
        }
        catch (FormatException) {
            Console.WriteLine("Bad String");
        }
    }
}
