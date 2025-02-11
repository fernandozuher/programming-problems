// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

using static System.Console;

static class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        bool isWeird = n % 2 == 1 || n >= 6 && n <= 20;
        WriteLine(isWeird ? "Weird" : "Not Weird");
    }
}
