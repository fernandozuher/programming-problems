// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        List<int> array = _readIntArray();
        Console.WriteLine(_kangaroo(array));
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static string _kangaroo(List<int> array)
        {
            int x1 = array[0];
            int v1 = array[1];
            int x2 = array[2];
            int v2 = array[3];

            if (v2 >= v1)
                return "NO";
            for (; x1 < x2; x1 += v1, x2 += v2);
            return x1 == x2 ? "YES" : "NO";
        }
}
