// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

using System;

enum HackosFine
{
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000
}

public class LibraryFine
{
    public static void Main()
    {
        DateTime returnDate = _ReadADate();
        DateTime dueDate = _ReadADate();

        int fine = _CalculateFine(returnDate, dueDate);
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


        private static int _CalculateFine(DateTime returnDate, DateTime dueDate)
        {
            int fine;

            if (_WereBooksReturnedInTime(returnDate, dueDate))
                fine = 0;
            else if (_IsReturnDateLateInMoreThanOrEqualToOneYear(returnDate.Year, dueDate.Year))
                fine = (int) HackosFine.HackosYearsFine;
            else if (_IsReturnDateLateInMoreThanOrEqualToOneMonth(returnDate.Month, dueDate.Month))
                fine = (returnDate.Month - dueDate.Month) * (int) HackosFine.HackosMonthsFine;
            else
                fine = (returnDate.Day - dueDate.Day) * (int) HackosFine.HackosDaysFine;

            return fine;
        }

            private static bool _WereBooksReturnedInTime(DateTime returnDate, DateTime dueDate)
            {
                if ((returnDate.Year < dueDate.Year) ||
                        ((returnDate.Year == dueDate.Year) && (returnDate.Month < dueDate.Month)) ||
                        ((returnDate.Year == dueDate.Year) && (returnDate.Month == dueDate.Month) && (returnDate.Day <= dueDate.Day))
                   )
                    return true;
                return false;
            }

            private static bool _IsReturnDateLateInMoreThanOrEqualToOneYear(int returnDateYear, int dueDateYear)
            {
                return returnDateYear > dueDateYear;
            }

            private static bool _IsReturnDateLateInMoreThanOrEqualToOneMonth(int returnDateMonth, int dueDateMonth)
            {
                return returnDateMonth > dueDateMonth;
            }
}
