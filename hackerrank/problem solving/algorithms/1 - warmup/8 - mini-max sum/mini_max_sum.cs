// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> array = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        array.Sort();
        _miniMaxSum(array);
    }

        private static void _miniMaxSum(List<int> array)
        {
            long sum = array.Aggregate(0L, (sum, num) => sum + num);
            long minSum = sum - array.Last();
            long maxSum = sum - array.First();
            Console.WriteLine("{0} {1}", minSum, maxSum);
        }
}
