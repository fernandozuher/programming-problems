// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

using System;

public class Solution {

    public static void Main() {
        int nTestCases = _ReadANumber();
        List<int> output = new List<int>(new int[nTestCases]);

        for (int i = 0; i < nTestCases; i++) {
            int number = _ReadANumber();
            FindDigits obj = new FindDigits(number);
            output[i] = obj.GetDivisors();
        }

        PrintOutput(output);
    }

        private static int _ReadANumber() {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        public static void PrintOutput(List<int> array) {
            array.ForEach(Console.WriteLine);
        }
}

    public class FindDigits {
        private int _Number;
        private int _Divisors;

        public FindDigits(int number) {
            _Number = number;
            _Divisors = 0;
            _FindNumberDivisorsQuantity();
        }

            private void _FindNumberDivisorsQuantity() {
                for (int currentNumber = _Number; currentNumber != 0; currentNumber = _RemoveLastDigitOfNumber(currentNumber)) {
                    int divisor = _GetLastDigitOfNumber(currentNumber);
                    if (_IsNumberEvenlyDividedByDivisor(divisor))
                        _Divisors++;
                }
            }

                private int _GetLastDigitOfNumber(int number) {
                    return number % 10;
                }

                private bool _IsNumberEvenlyDividedByDivisor(int divisor) {
                    return divisor != 0 && _Number % divisor == 0;
                }

                private int _RemoveLastDigitOfNumber(int number) {
                    return number / 10;
                }

        public int GetDivisors() {
            return _Divisors;
        }
    }
