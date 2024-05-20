// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int num1 = int.Parse(ReadLine());
        int num2 = int.Parse(ReadLine());
        WriteLine(SolveMeFirst(num1, num2));
    }

        static int SolveMeFirst(int a, int b)
        {
            return a + b;
        }
}
