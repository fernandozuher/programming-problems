// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> line = _readIntArray();
        int startingDayNumber = line.First();
        int endingDayNumber = line[1];
        int divisor = line.Last();
        var obj = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
        Console.WriteLine(obj.NBeautifulDays);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class BeautifulDays
    {
        private int _startingDayNumber;
        private int _endingDayNumber;
        private int _divisor;
        private int _nBeautifulDays;

        public BeautifulDays(int startingDayNumber, int endingDayNumber, int divisor)
        {
            _startingDayNumber = startingDayNumber;
            _endingDayNumber = endingDayNumber;
            _divisor = divisor;
            _nBeautifulDays = 0;
            _calculateBeautifulDaysQuantity();
        }

            private void _calculateBeautifulDaysQuantity()
            {
                for (int number = _startingDayNumber; number <= _endingDayNumber; ++number)
                {
                    int reverseNumber = _generateReverseNumber(number);
                    if (_isDayBeautiful(number, reverseNumber))
                        ++_nBeautifulDays;
                }
            }

                private int _generateReverseNumber(int number)
                {
                    int reverseNumber = 0;
                    for (; number > 0; number /= 10)
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                private bool _isDayBeautiful(int number, int reverseNumber)
                {
                    return Math.Abs(number - reverseNumber) % _divisor == 0;
                }

        public int NBeautifulDays
        {
            get { return _nBeautifulDays; }
        }
    }
