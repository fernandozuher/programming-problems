// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

using System;

public class ModifiedKrapekarNumbers
{
    public static void Main()
    {
        int lowerLimit = int.Parse(Console.ReadLine());
        int upperLimit = int.Parse(Console.ReadLine());

        List<int> output = _findKaprekarNumbersInRange(lowerLimit, upperLimit);
        printOutput(output);
    }

    private static List<int> _findKaprekarNumbersInRange(int lowerLimit, int upperLimit)
    {
        List<int> kaprekarNumbers = new List<int>();

        for (int number = lowerLimit; number <= upperLimit; number++)
        {
            int potentialKaprekarNumber = _calculatePotentialKaprekarNumber(number);
            if (number == potentialKaprekarNumber)
                kaprekarNumbers.Add(number);
        }

        return kaprekarNumbers;
    }

        private static int _calculatePotentialKaprekarNumber(int number)
        {
            string squareNumberInString = System.Numerics.BigInteger.Pow(number, 2).ToString();
            int lengthOfNumberInString = number.ToString().Length;

            string leftNumberInString = _getLeftNumberInString(squareNumberInString, lengthOfNumberInString);
            string rightNumberInString = _getRightNumberInString(squareNumberInString, lengthOfNumberInString);

            int potentialKaprekarNumber = _sumNumbersInStrings(leftNumberInString, rightNumberInString);

            return potentialKaprekarNumber;
        }

            private static string _getLeftNumberInString(string squareNumberInString, int lengthOfNumberInString)
            {
                int digitsToSkip = 0;
                int digitsToTake = squareNumberInString.Length - lengthOfNumberInString;
                string numberInString = squareNumberInString.Substring(digitsToSkip, digitsToTake);
                return numberInString;
            }

            private static string _getRightNumberInString(string squareNumberInString, int lengthOfNumberInString)
            {
                int digitsToSkip = squareNumberInString.Length - lengthOfNumberInString;
                string numberInString = squareNumberInString.Substring(digitsToSkip);
                return numberInString;
            }

            private static int _sumNumbersInStrings(string leftNumberInString, string rightNumberInString)
            {
                if (leftNumberInString.Length > 0 && rightNumberInString.Length > 0)
                    return int.Parse(leftNumberInString) + int.Parse(rightNumberInString);
                else if (leftNumberInString.Length == 0)
                    return int.Parse(rightNumberInString);
                else if (rightNumberInString.Length == 0)
                    return int.Parse(leftNumberInString);
                return 0;
            }

    public static void printOutput(List<int> array)
    {
        if (array.Any())
            array.ForEach(element => Console.Write(element + " "));
        else
            Console.WriteLine("INVALID RANGE");
    }
}
