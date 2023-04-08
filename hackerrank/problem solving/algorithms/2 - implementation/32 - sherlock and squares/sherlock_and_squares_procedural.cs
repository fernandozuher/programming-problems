// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

using System;

public class SherlockAndSquares
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
            output[i] = _CalculateNumberOfSquareintsInRange(begin, end);
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

        private static int _CalculateNumberOfSquareintsInRange(int begin, int end)
        {
            int squares = 0;
            for (int number = _FindFirstSquareIntegerFromNumber(begin); _IsPowerOf2OfNumberLessThanOrEqualToLimit(number, end); number++)
                squares++;
            return squares;
        }

            private static int _FindFirstSquareIntegerFromNumber(int number)
            {
                double squareRootNumber = Math.Sqrt(number);
                int squareInteger = _GetSquareIntegerFromNumber(squareRootNumber);
                return squareInteger;
            }

                private static int _GetSquareIntegerFromNumber(double number)
                {
                    int integerPart = (int) Math.Floor(number);
                    return number == integerPart ? integerPart : integerPart + 1;
                }

            private static bool _IsPowerOf2OfNumberLessThanOrEqualToLimit(int number, int limit)
            {
                return Math.Pow(number, 2) <= limit;
            }

        public static void PrintArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}
