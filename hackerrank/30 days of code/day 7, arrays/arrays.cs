// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();

        for (int i = n - 1; i >= 0; i--)
            Console.Write("{0} ", array[i]);
    }
}
