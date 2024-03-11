// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        var list = ReadIntArray();
        int n = list.First(), rotateBy = list.Last();
        List<int> array = ReadIntArray();

        if (rotateBy > n - 1)
            rotateBy %= n;

        array = Rotate(array, rotateBy);
        Console.WriteLine(string.Join(" ", array));
    }

        public static List<int> ReadIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        public static List<int> Rotate(List<int> array, int n)
        {
            return array.Skip(n).Concat(array.Take(n)).ToList();
        }
}
