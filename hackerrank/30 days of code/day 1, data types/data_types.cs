// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        const int i = 4;
        const double d = 4.0;
        const string s = "HackerRank ";

        var i2 = int.Parse(ReadLine());
        var d2 = double.Parse(ReadLine());
        var s2 = ReadLine();

        WriteLine(i + i2);
        WriteLine("{0:0.0}", d + d2);
        WriteLine(s + s2);
    }
}