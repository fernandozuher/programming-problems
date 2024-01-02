// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        List<int> chocolateSquares = readIntArray();
        List<int> dayMonth = readIntArray();

        var obj = new TheBirthdayBar(chocolateSquares, dayMonth);
        Console.WriteLine(obj.waysBarCanBeDivided());
    }

        private static List<int> readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class TheBirthdayBar
    {
        private List<int> _chocolateSquares;
        private int _day, _month;
        private int _waysBarCanBeDivided;

        public TheBirthdayBar(List<int> chocolateSquares, List<int> dayMonth)
        {
            _chocolateSquares = chocolateSquares;
            _day = dayMonth.First();
            _month = dayMonth.Last();
            _waysBarCanBeDivided = 0;

            _birthday();
        }

            private void _birthday()
            {
                for (int i = 0, n1 = _chocolateSquares.Count - _month + 1; i < n1; ++i)
                {
                    int sum = 0;
                    for (int j = i, n2 = i + _month; j < n2; sum += _chocolateSquares[j++]);
                    if (sum == _day)
                        ++_waysBarCanBeDivided;
                }
            }

        public int waysBarCanBeDivided()
        {
            return _waysBarCanBeDivided;
        }
    }
