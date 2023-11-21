// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        Console.WriteLine(_birthdayCakeCandles(array));
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        }

        private static int _birthdayCakeCandles(List<int> candles)
        {
            int maxElement = candles.Max();
            int count = candles.Count(number => number == maxElement);
            return count;
        }
}
