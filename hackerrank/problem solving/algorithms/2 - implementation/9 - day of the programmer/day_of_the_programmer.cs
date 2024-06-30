// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int year = int.Parse(ReadLine()!);
        var obj = new DayOfTheProgrammer(year);
        obj.calculateDateOf256thDay();
        WriteLine(obj.Date);
    }
}

    class DayOfTheProgrammer(int year)
    {
        private const int TransitionYear = 1918;
        private readonly int _year = year;
        public string Date { get; private set; } = "";

        public void calculateDateOf256thDay()
        {
            if (_year != TransitionYear)
                Date = _isLeapYear() ? "12.09." : "13.09.";
            else
                Date = "26.09.";
            Date += _year.ToString();
        }

            private bool _isLeapYear()
            {
                return _year > TransitionYear ? _isLeapGregorianYear() : _isLeapJulianYear();
            }

                private bool _isLeapGregorianYear()
                {
                    return _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
                }

                private bool _isLeapJulianYear()
                {
                    return _year % 4 == 0;
                }
    }
