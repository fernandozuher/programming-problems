// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        _plusMinus(array);
    }

    private static List<int> _readIntArray()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
    }

    private static void _plusMinus(List<int> array)
    {
        int positive = 0;
        int negative = 0;
        int zero = 0;

        foreach (int number in array)
            if (number > 0)
                ++positive;
            else if (number < 0)
                ++negative;
            else
                ++zero;

        int n = array.Count;
        double positiveProportion = (double) positive / n;
        double negativeProportion = (double) negative / n;
        double zeroProportion = (double) zero / n;

        Console.WriteLine("{0:0.000000}", positiveProportion);
        Console.WriteLine("{0:0.000000}", negativeProportion);
        Console.WriteLine("{0:0.000000}", zeroProportion);
    }
}
