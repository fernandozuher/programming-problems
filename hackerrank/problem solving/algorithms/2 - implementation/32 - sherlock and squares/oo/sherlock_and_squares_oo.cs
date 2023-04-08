// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int nTestCases = _ReadANumber();
        List<int> output = new List<int>(new int[nTestCases]);

        for (int i = 0; i < nTestCases; i++)
        {
            List<int> arrayInput = _ReadAnArray();
            int begin = arrayInput.First();
            int end = arrayInput.Last();

            SherlockAndSquares obj = new SherlockAndSquares(begin, end);
            output[i] = obj.GetQuantityOfSquareIntegers();
        }

        PrintArray(output);
    }

        private static int _ReadANumber()
        {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static List<int> _ReadAnArray()
        {
            List<int> array = Console.ReadLine().Split(" ").Select(int.Parse).ToList();
            return array;
        }

        public static void PrintArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}

    public class SherlockAndSquares
    {
        private int _Begin;
        private int _End;
        private int _QuantityOfSquareIntegers;

        public SherlockAndSquares(int begin, int end)
        {
            _Begin = begin;
            _End = end;
            _QuantityOfSquareIntegers = 0;

            _CalculateNumberOfSquareIntegersInRange();
        }

            private void _CalculateNumberOfSquareIntegersInRange()
            {
                for (int number = _FindFirstSquareIntegerFromBeginNumber(); _IsPowerOf2OfNumberLessThanOrEqualToEndNumber(number); number++)
                    _QuantityOfSquareIntegers++;
            }

                private int _FindFirstSquareIntegerFromBeginNumber()
                {
                    double squareRootNumber = Math.Sqrt(_Begin);
                    int squareInteger = _GetSquareIntegerFromNumber(squareRootNumber);
                    return squareInteger;
                }

                    private int _GetSquareIntegerFromNumber(double number)
                    {
                        int integerPart = (int) Math.Floor(number);
                        return number == integerPart ? integerPart : integerPart + 1;
                    }

                private bool _IsPowerOf2OfNumberLessThanOrEqualToEndNumber(int number)
                {
                    return Math.Pow(number, 2) <= _End;
                }

        public int GetQuantityOfSquareIntegers()
        {
            return _QuantityOfSquareIntegers;
        }
    }
