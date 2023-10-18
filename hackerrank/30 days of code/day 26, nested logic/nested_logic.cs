// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        DateTime returnedRealDate, dueDate;
        _readStdinDates(out returnedRealDate, out dueDate);
        var bookReturnDate = new BookReturnDate(returnedRealDate, dueDate);
        Console.WriteLine(bookReturnDate.Fine());
    }

        private static void _readStdinDates(out DateTime returnedRealDate, out DateTime dueDate)
        {
            List<int> numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            returnedRealDate = new DateTime(numbers[2], numbers[1], numbers[0]);

            numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            dueDate = new DateTime(numbers[2], numbers[1], numbers[0]);
        }
}

    public class BookReturnDate
    {
        private DateTime _returnedRealDate, _dueDate;
        private int _fine;

        public BookReturnDate(DateTime returnedRealDate, DateTime dueDate)
        {
            _returnedRealDate = returnedRealDate;
            _dueDate = dueDate;
            _calculateFine();
        }

            private void _calculateFine()
            {
                if (_returnedRealDate <= _dueDate)
                    _fine = 0;
                else if (_returnedRealDate.Year == _dueDate.Year)
                {
                    if (_returnedRealDate.Month == _dueDate.Month)
                        _fine = (_returnedRealDate.Day - _dueDate.Day) * (int) HackosFine.HackosDaysFine;
                    else
                        _fine = (_returnedRealDate.Month - _dueDate.Month) * (int) HackosFine.HackosMonthsFine;
                }
                else
                    _fine = (int) HackosFine.HackosYearsFine;
            }

        public int Fine()
        {
            return _fine;
        }
    }

        enum HackosFine
        {
            HackosDaysFine = 15,
            HackosMonthsFine = 500,
            HackosYearsFine = 10000
        }
