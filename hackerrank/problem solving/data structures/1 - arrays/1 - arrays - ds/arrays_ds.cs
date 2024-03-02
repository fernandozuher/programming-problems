// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
        array = ReverseArray(array);
        array.ForEach(x => Console.Write("{0} ", x));
    }

        public static List<int> ReverseArray(List<int> array)
        {
            array.Reverse();
            return array;
        }
}
