// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

using static System.Console;

class Solution
{
    public static void Main()
    {
        string s = ReadLine();
        try
        {
            WriteLine(int.Parse(s));
        }
        catch (FormatException)
        {
            WriteLine("Bad String");
        }
    }
}
