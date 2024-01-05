// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int year = int.Parse(Console.ReadLine());
        var obj = new DayOfTheProgrammer(year);
        Console.WriteLine(obj.Date);
    }
}

    public class DayOfTheProgrammer
    {
        private static int TransitionYear = 1918;
        private int _year;
        private string _date;

        public DayOfTheProgrammer(int year)
        {
            _year = year;
            _date = "";
            _findDateOf256thDay();
        }

            private void _findDateOf256thDay()
            {
                _findDayMonthOf256thDay();
                _date += _year.ToString();
            }

                private void _findDayMonthOf256thDay()
                {
                    if (_year != TransitionYear)
                        _date = _isLeapYear() ? "12.09." : "13.09.";
                    else
                        _date = "26.09.";
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

        public string Date
        {
            get { return _date; }
        }
    }
