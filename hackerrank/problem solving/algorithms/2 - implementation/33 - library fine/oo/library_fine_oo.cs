// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

using System;

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
        DateTime returnDate = _ReadADate();
        DateTime dueDate = _ReadADate();

        LibraryFine obj = new LibraryFine(returnDate, dueDate);
        int fine = obj.GetFine();
        Console.WriteLine(fine);
    }

        private static DateTime _ReadADate()
        {
            List<int> dateAsAList = Console.ReadLine().Split().Select(int.Parse).ToList();
            int day = dateAsAList.First();
            int month = dateAsAList[1];
            int year = dateAsAList.Last();

            DateTime date = new DateTime(year, month, day);
            return date;
        }
}

    public class LibraryFine
    {
        private DateTime _ReturnDate;
        private DateTime _DueDate;
        private int _Fine;

        public LibraryFine(DateTime returnDate, DateTime dueDate)
        {
            _ReturnDate = returnDate;
            _DueDate = dueDate;
            _Fine = 0;

            _CalculateFine();
        }

            private void _CalculateFine()
            {
                if (_WereBooksReturnedInTime())
                    _Fine = 0;
                else if (_IsReturnDateLateInMoreThanOrEqualToOneYear())
                    _Fine = (int) HackosFine.HackosYearsFine;
                else if (_IsReturnDateLateInMoreThanOrEqualToOneMonth())
                    _Fine = (_ReturnDate.Month - _DueDate.Month) * (int) HackosFine.HackosMonthsFine;
                else
                    _Fine = (_ReturnDate.Day - _DueDate.Day) * (int) HackosFine.HackosDaysFine;
            }

                private bool _WereBooksReturnedInTime()
                {
                    if ((_ReturnDate.Year < _DueDate.Year) ||
                            ((_ReturnDate.Year == _DueDate.Year) && (_ReturnDate.Month < _DueDate.Month)) ||
                            ((_ReturnDate.Year == _DueDate.Year) && (_ReturnDate.Month == _DueDate.Month) && (_ReturnDate.Day <= _DueDate.Day))
                       )
                        return true;
                    return false;
                }

                private bool _IsReturnDateLateInMoreThanOrEqualToOneYear()
                {
                    return _ReturnDate.Year > _DueDate.Year;
                }

                private bool _IsReturnDateLateInMoreThanOrEqualToOneMonth()
                {
                    return _ReturnDate.Month > _DueDate.Month;
                }

        public int GetFine()
        {
            return _Fine;
        }
    }
