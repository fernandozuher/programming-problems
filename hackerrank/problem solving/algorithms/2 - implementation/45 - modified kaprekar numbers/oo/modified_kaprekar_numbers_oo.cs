// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int lowerLimit = int.Parse(Console.ReadLine());
        int upperLimit = int.Parse(Console.ReadLine());

        KaprekarNumbers obj = new KaprekarNumbers(lowerLimit, upperLimit);
        PrintOutput(obj.GetKaprekarNumbers());
    }

    public static void PrintOutput(List<int> array)
    {
        if (array.Any())
            array.ForEach(element => Console.Write(element + " "));
        else
            Console.WriteLine("INVALID RANGE");
    }
}

    public class KaprekarNumbers
    {
        private int _lowerLimit, _upperLimit;
        private List<int> _kaprekarNumbers;

        public KaprekarNumbers(int lowerLimit, int upperLimit)
        {
            _lowerLimit = lowerLimit;
            _upperLimit = upperLimit;
            _kaprekarNumbers = new List<int>();

            _findKaprekarNumbersInRange();
        }

            private void _findKaprekarNumbersInRange()
            {
                for (int number = _lowerLimit; number <= _upperLimit; number++)
                {
                    int potentialKaprekarNumber = _calculatePotentialKaprekarNumber(number);
                    if (number == potentialKaprekarNumber)
                        _kaprekarNumbers.Add(number);
                }
            }

                private int _calculatePotentialKaprekarNumber(int number)
                {
                    string squareNumberInString = System.Numerics.BigInteger.Pow(number, 2).ToString();
                    int lengthOfNumberInString = number.ToString().Length;

                    string leftNumberInString = _getLeftNumberInString(squareNumberInString, lengthOfNumberInString);
                    string rightNumberInString = _getRightNumberInString(squareNumberInString, lengthOfNumberInString);

                    int potentialKaprekarNumber = _sumNumbersInStrings(leftNumberInString, rightNumberInString);

                    return potentialKaprekarNumber;
                }

                    private string _getLeftNumberInString(string squareNumberInString, int lengthOfNumberInString)
                    {
                        int digitsToSkip = 0;
                        int digitsToTake = squareNumberInString.Length - lengthOfNumberInString;
                        string numberInString = squareNumberInString.Substring(digitsToSkip, digitsToTake);
                        return numberInString;
                    }

                    private string _getRightNumberInString(string squareNumberInString, int lengthOfNumberInString)
                    {
                        int digitsToSkip = squareNumberInString.Length - lengthOfNumberInString;
                        string numberInString = squareNumberInString.Substring(digitsToSkip);
                        return numberInString;
                    }

                    private int _sumNumbersInStrings(string leftNumberInString, string rightNumberInString)
                    {
                        if (leftNumberInString.Length > 0 && rightNumberInString.Length > 0)
                            return int.Parse(leftNumberInString) + int.Parse(rightNumberInString);
                        else if (leftNumberInString.Length == 0)
                            return int.Parse(rightNumberInString);
                        else if (rightNumberInString.Length == 0)
                            return int.Parse(leftNumberInString);
                        return 0;
                    }

        public List<int> GetKaprekarNumbers()
        {
            return _kaprekarNumbers;
        }
    }
