// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    static void Main()
    {
        int lowerLimit = int.Parse(ReadLine());
        int upperLimit = int.Parse(ReadLine());
        bool validRange = false;

        foreach (var number in Enumerable.Range(lowerLimit, upperLimit - lowerLimit + 1))
        {
            if (IsNumberKaprekar(number))
            {
                Write(number + " ");
                validRange = true;
            }
        }

        if (!validRange)
            WriteLine("INVALID RANGE");
    }

        static bool IsNumberKaprekar(int number)
        {
            long squareNumber = (long)Math.Pow(number, 2);
            long divisor = (long)Math.Pow(10, NumberDigits(number));
            long leftNumber = Math.DivRem(squareNumber, divisor, out long rightNumber);
            return number == leftNumber + rightNumber;
        }

            static int NumberDigits(long n)
            {
                if (n < 10) return 1;
                if (n < 100) return 2;
                if (n < 1000) return 3;
                if (n < 10000) return 4;
                if (n < 100000) return 5;
                if (n < 1000000) return 6;
                if (n < 10000000) return 7;
                return 8;
            }
}
