// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

enum HackosFine
{
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000
}

public class Solution
{
    public static void Main()
    {
        DateTime returnDate = ReadADate();
        DateTime dueDate = ReadADate();
        var obj = new LibraryFine(returnDate, dueDate);
        Console.WriteLine(obj.Fine);
    }

        public static DateTime ReadADate()
        {
            List<int> dateAsAList = Console.ReadLine().Split().Select(int.Parse).ToList();
            int day = dateAsAList.First();
            int month = dateAsAList[1];
            int year = dateAsAList.Last();

            return new DateTime(year, month, day);
        }
}

    public class LibraryFine
    {
        private DateTime _returnDate;
        private DateTime _dueDate;
        private int _fine;

        public LibraryFine(DateTime returnDate, DateTime dueDate)
        {
            _returnDate = returnDate;
            _dueDate = dueDate;
            _fine = 0;
            _calculateFine();
        }

            private void _calculateFine()
            {
                if (_wereBooksReturnedInTime())
                    _fine = 0;
                else if (_isReturnDateLateInMoreThanOrEqualToOneYear())
                    _fine = (int) HackosFine.HackosYearsFine;
                else if (_isReturnDateLateInMoreThanOrEqualToOneMonth())
                    _fine = (_returnDate.Month - _dueDate.Month) * (int) HackosFine.HackosMonthsFine;
                else
                    _fine = (_returnDate.Day - _dueDate.Day) * (int) HackosFine.HackosDaysFine;
            }

                private bool _wereBooksReturnedInTime()
                {
                    if ((_returnDate.Year < _dueDate.Year) ||
                            ((_returnDate.Year == _dueDate.Year) && (_returnDate.Month < _dueDate.Month)) ||
                            ((_returnDate.Year == _dueDate.Year) && (_returnDate.Month == _dueDate.Month) && (_returnDate.Day <= _dueDate.Day))
                       )
                        return true;
                    return false;
                }

                private bool _isReturnDateLateInMoreThanOrEqualToOneYear()
                {
                    return _returnDate.Year > _dueDate.Year;
                }

                private bool _isReturnDateLateInMoreThanOrEqualToOneMonth()
                {
                    return _returnDate.Month > _dueDate.Month;
                }

        public int Fine
        {
            get { return _fine; }
        }
    }