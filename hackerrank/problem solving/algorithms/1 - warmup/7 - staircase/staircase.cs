// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        Staircase(n);
    }

        static void Staircase(int n)
        {
            foreach (int i in Enumerable.Range(1, n))
            {
                foreach (int j in Enumerable.Range(0, n - i))
                    Write(" ");
                foreach (int k in Enumerable.Range(0, i))
                    Write("#");
                WriteLine();
            }
        }
}
