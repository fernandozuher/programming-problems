// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var output = new List<int>(new int[n]);

        for (int i = 0; i < n; ++i)
        {
            List<int> input = ReadIntArray();
            int begin = input.First();
            int end = input.Last();

            var obj = new SherlockAndSquares(begin, end);
            output[i] = obj.SquareIntegers;
        }

        output.ForEach(Console.WriteLine);
    }

        public static List<int> ReadIntArray()
        {
            return Console.ReadLine().Split(" ").Select(int.Parse).ToList();
        }
}

    public class SherlockAndSquares
    {
        private int _begin;
        private int _end;
        private int _squareIntegers;

        public SherlockAndSquares(int begin, int end)
        {
            _begin = begin;
            _end = end;
            _squareIntegers = 0;
            _calculateQuantityOfSquareIntegersInRange();
        }

            private void _calculateQuantityOfSquareIntegersInRange()
            {
                for (int number = _findFirstSquareInteger(); _isPowerOf2LessThanOrEqualToLimit(number); ++number)
                    ++_squareIntegers;
            }

                private int _findFirstSquareInteger()
                {
                    double squareRoot = Math.Sqrt(_begin);
                    int integerPart = (int) Math.Floor(squareRoot);
                    return squareRoot == integerPart ? integerPart : integerPart + 1;
                }

                private bool _isPowerOf2LessThanOrEqualToLimit(int x)
                {
                    return Math.Pow(x, 2) <= _end;
                }

        public int SquareIntegers
        {
            get { return _squareIntegers; }
        }
    }
