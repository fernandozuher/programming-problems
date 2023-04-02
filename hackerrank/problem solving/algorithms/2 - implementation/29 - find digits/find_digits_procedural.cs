// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

using System;

public class Solution {

    public static void Main() {
        int nTestCases = _ReadANumber();
        List<int> output = new List<int>(new int[nTestCases]);

        for (int i = 0; i < nTestCases; i++) {
            int number = _ReadANumber();
            output[i] = _FindNumberDivisorsQuantity(number);
        }

        PrintOutput(output);
    }

        private static int _ReadANumber() {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static int _FindNumberDivisorsQuantity(int number) {
            int divisors = 0;

            for (int currentNumber = number; currentNumber != 0; currentNumber /= 10) {
                int potentialDivisor = currentNumber % 10;
                if (_IsNumberEvenlyDividedByDivisor(number, potentialDivisor))
                    divisors++;
            }

            return divisors;
        }

            private static bool _IsNumberEvenlyDividedByDivisor(int number, int divisor) {
                return divisor != 0 && number % divisor == 0;
            }

        public static void PrintOutput(List<int> array) {
            array.ForEach(Console.WriteLine);
        }
}
