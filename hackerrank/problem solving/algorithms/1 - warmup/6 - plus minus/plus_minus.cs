// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readAnIntArray();
        _plusMinus(array);
    }

    private static List<int> _readAnIntArray()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
    }

    private static void _plusMinus(List<int> array)
    {
        int positiveQuantity = 0;
        int negativeQuantity = 0;
        int zeroQuantity = 0;

        foreach (int number in array)
            if (number > 0)
                ++positiveQuantity;
            else if (number < 0)
                ++negativeQuantity;
            else
                ++zeroQuantity;

        int n = array.Count;
        double positiveValuesProportion = (double) positiveQuantity / n;
        double negativeValuesProportion = (double) negativeQuantity / n;
        double zeroValuesProportion = (double) zeroQuantity / n;

        Console.WriteLine("{0:0.000000}", positiveValuesProportion);
        Console.WriteLine("{0:0.000000}", negativeValuesProportion);
        Console.WriteLine("{0:0.000000}", zeroValuesProportion);
    }
}
