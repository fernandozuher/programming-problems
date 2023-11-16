// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = Console.ReadLine().Split(" ").Select(int.Parse).ToList();
        Console.WriteLine("{0}", _aVeryBigSum(array));
    }

        private static long _aVeryBigSum(List<int> array)
        {
            return array.Aggregate(0L, (sum, number) => sum + number);
        }
}
