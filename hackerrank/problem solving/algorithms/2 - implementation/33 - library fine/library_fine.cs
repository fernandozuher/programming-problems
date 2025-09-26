// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

enum HackosFine
{
    DaysFine = 15,
    MonthsFine = 500,
    YearsFine = 10000
}

public class Solution
{
    public static void Main()
    {
        DateTime returnDate = ReadDate();
        DateTime dueDate = ReadDate();
        Console.WriteLine(CalculateFine(returnDate, dueDate));
    }

    private static DateTime ReadDate()
    {
        var dateAsArray = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
        int day = dateAsArray[0];
        int month = dateAsArray[1];
        int year = dateAsArray[2];
        return new DateTime(year, month, day);
    }

    private static int CalculateFine(DateTime returnDate, DateTime dueDate)
    {
        if (ReturnedOnTime(returnDate, dueDate))
            return 0;
        if (returnDate.Year > dueDate.Year)
            return (int)HackosFine.YearsFine;
        if (returnDate.Month > dueDate.Month)
            return (returnDate.Month - dueDate.Month) * (int)HackosFine.MonthsFine;
        return (returnDate.Day - dueDate.Day) * (int)HackosFine.DaysFine;
    }

    private static bool ReturnedOnTime(DateTime returnDate, DateTime dueDate)
    {
        return (returnDate.Year < dueDate.Year) ||
                ((returnDate.Year == dueDate.Year) && (returnDate.Month < dueDate.Month)) ||
                ((returnDate.Year == dueDate.Year) && (returnDate.Month == dueDate.Month) && (returnDate.Day <= dueDate.Day));
    }
}
