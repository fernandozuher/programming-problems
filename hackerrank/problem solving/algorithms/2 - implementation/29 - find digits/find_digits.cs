// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var nNumberDivisors = new List<int>(new int[n]);

        for (int i = 0; i < n; ++i)
        {
            int number = _readInt();
            var obj = new FindDigits(number);
            nNumberDivisors[i] = obj.Divisors;
        }

        nNumberDivisors.ForEach(Console.WriteLine);
    }

        private static int _readInt()
        {
            return int.Parse(Console.ReadLine());
        }
}

    public class FindDigits
    {
        private int _number;
        private int _divisors;

        public FindDigits(int number)
        {
            _number = number;
            _divisors = 0;
            _findNumberDivisorsQuantity();
        }

            private void _findNumberDivisorsQuantity()
            {
                for (int currentNumber = _number; currentNumber != 0; currentNumber = _removeLastDigitOfNumber(currentNumber))
                {
                    int divisor = _getLastDigitOfNumber(currentNumber);
                    if (_isNumberEvenlyDividedByDivisor(divisor))
                        ++_divisors;
                }
            }

                private int _getLastDigitOfNumber(int number)
                {
                    return number % 10;
                }

                private bool _isNumberEvenlyDividedByDivisor(int divisor)
                {
                    return divisor != 0 && _number % divisor == 0;
                }

                private int _removeLastDigitOfNumber(int number)
                {
                    return number / 10;
                }

        public int Divisors
        {
            get { return _divisors; }
        }
    }
