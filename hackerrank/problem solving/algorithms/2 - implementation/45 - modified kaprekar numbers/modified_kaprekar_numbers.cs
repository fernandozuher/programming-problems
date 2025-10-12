// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int lower = int.Parse(Console.ReadLine()!);
        int upper = int.Parse(Console.ReadLine()!);
        bool validRange = false;

        for (int number = lower; number <= upper; number++)
            if (IsNumberKaprekar(number))
            {
                Console.Write(number + " ");
                validRange = true;
            }

        if (!validRange)
            Console.WriteLine("INVALID RANGE");
    }

    private static bool IsNumberKaprekar(int number)
    {
        long squareNumber = (long)Math.Pow(number, 2);
        long divisor = (long)Math.Pow(10, NumberDigits(number));
        long leftNumber = Math.DivRem(squareNumber, divisor, out long rightNumber);
        return number == leftNumber + rightNumber;
    }

    private static int NumberDigits(long n)
    {
        return n.ToString().Length;
    }
}
