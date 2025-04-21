// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        DateTime returnedRealDate = ReadDate();
        DateTime dueDate = ReadDate();
        WriteLine(returnedRealDate <= dueDate ? 0 : CalculateFine(returnedRealDate, dueDate));
    }

    private static DateTime ReadDate()
    {
        var dateParts = ReadLine().Split(" ").Select(int.Parse).ToArray();
        int day = dateParts[0], month = dateParts[1], year = dateParts[2];
        return new DateTime(year, month, day);
    }

    private static int CalculateFine(DateTime returnedRealDate, DateTime dueDate)
    {
        int fine = LateByYear(returnedRealDate, dueDate);
        if (fine != 0)
            return fine;

        fine = LateByMonth(returnedRealDate, dueDate);
        if (fine != 0)
            return fine;

        return LateByDay(returnedRealDate, dueDate);
    }

    private static int LateByYear(DateTime returnedRealDate, DateTime dueDate)
    {
        if (returnedRealDate.Year > dueDate.Year)
        {
            const int perYear = 10000;
            return perYear;
        }
        return 0;
    }

    private static int LateByMonth(DateTime returnedRealDate, DateTime dueDate)
    {
        if (returnedRealDate.Year == dueDate.Year && returnedRealDate.Month > dueDate.Month)
        {
            const int perMonth = 500;
            return (returnedRealDate.Month - dueDate.Month) * perMonth;
        }
        return 0;
    }

    private static int LateByDay(DateTime returnedRealDate, DateTime dueDate)
    {
        if (returnedRealDate.Year == dueDate.Year && returnedRealDate.Month == dueDate.Month &&
            returnedRealDate.Day > dueDate.Day)
        {
            const int perDay = 15;
            return (returnedRealDate.Day - dueDate.Day) * perDay;
        }
        return 0;
    }
}
