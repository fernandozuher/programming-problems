// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
        Console.WriteLine(_simpleArraySum(array));

    }

        private static int _simpleArraySum(List<int> array)
        {
            return array.Aggregate(0, (sum, num) => sum + num);
        }
}
