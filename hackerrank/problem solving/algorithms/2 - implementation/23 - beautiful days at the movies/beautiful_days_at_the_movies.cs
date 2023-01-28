// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        List<int> inputLine = _ReadLineAsListInt();
        int startingDayNumber = inputLine.First();
        int endingDayNumber = inputLine[1];
        int divisor = inputLine.Last();

        BeautifulDays beautifulDays = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
    }

        private static List<int> _ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class BeautifulDays
    {
        private int _startingDayNumber;
        private int _endingDayNumber;
        private int _divisor;
        private int _nBeautifulDays;

        public BeautifulDays(int startingDayNumber, int endingDayNumber, int divisor)
        {
            _startingDayNumber = startingDayNumber;
            _endingDayNumber = endingDayNumber;
            _divisor = divisor;
            _nBeautifulDays = 0;

            _BeautifulDays();
            PrintNBeautifulDays();
        }

            private void _BeautifulDays()
            {
                for (int number = _startingDayNumber; number <= _endingDayNumber; number++)
                {
                    int reverseNumber = _GenerateReverseNumber(number);
                    if (_IsDayBeautiful(number, reverseNumber))
                        _nBeautifulDays++;
                }
            }

                private int _GenerateReverseNumber(int number)
                {
                    int reverseNumber = 0;
                    for (; number > 0; number /= 10)
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                private bool _IsDayBeautiful(int number, int reverseNumber)
                {
                    bool beautifulDay = Math.Abs(number - reverseNumber) % _divisor == 0;
                    return beautifulDay;
                }

        public void PrintNBeautifulDays()
        {
            Console.WriteLine(_nBeautifulDays);
        }
}
