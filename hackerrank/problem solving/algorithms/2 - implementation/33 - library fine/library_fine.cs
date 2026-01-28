// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

DateTime returnDate = ReadDate();
DateTime dueDate = ReadDate();
Console.WriteLine(CalculateFine(returnDate, dueDate));

DateTime ReadDate()
{
    var arr = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    int day = arr[0];
    int month = arr[1];
    int year = arr[2];
    return new DateTime(year, month, day);
}

// T: O(1)
// S: O(1) extra space
int CalculateFine(DateTime returnDate, DateTime dueDate)
{
    if (IsYearLate(returnDate, dueDate))
        return (int)HackosFine.YearsFine;
    if (IsMonthLate(returnDate, dueDate))
        return (returnDate.Month - dueDate.Month) * (int)HackosFine.MonthsFine;
    if (IsDayLate(returnDate, dueDate))
        return (returnDate.Day - dueDate.Day) * (int)HackosFine.DaysFine;
    return 0;
}

bool IsYearLate(DateTime returnDate, DateTime dueDate)
{
    return returnDate.Year > dueDate.Year;
}

bool IsMonthLate(DateTime returnDate, DateTime dueDate)
{
    return returnDate.Year == dueDate.Year && returnDate.Month > dueDate.Month;
}

bool IsDayLate(DateTime returnDate, DateTime dueDate)
{
    return returnDate.Year == dueDate.Year && returnDate.Month == dueDate.Month && returnDate.Day > dueDate.Day;
}

enum HackosFine
{
    DaysFine = 15,
    MonthsFine = 500,
    YearsFine = 10000
}
