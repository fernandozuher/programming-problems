// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

DateTime returnDate = ReadDate();
DateTime dueDate = ReadDate();
Console.WriteLine(CalculateFine(returnDate, dueDate));

DateTime ReadDate()
{
    var nums = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    int day = nums[0];
    int month = nums[1];
    int year = nums[2];
    return new DateTime(year, month, day);
}

int CalculateFine(DateTime returnDate, DateTime dueDate)
{
    if (ReturnedOnTime(returnDate, dueDate))
        return 0;
    if (returnDate.Year > dueDate.Year)
        return (int)HackosFine.YearsFine;
    if (returnDate.Month > dueDate.Month)
        return (returnDate.Month - dueDate.Month) * (int)HackosFine.MonthsFine;
    return (returnDate.Day - dueDate.Day) * (int)HackosFine.DaysFine;
}

bool ReturnedOnTime(DateTime returnDate, DateTime dueDate)
{
    return (returnDate.Year < dueDate.Year) ||
            ((returnDate.Year == dueDate.Year) && (returnDate.Month < dueDate.Month)) ||
            ((returnDate.Year == dueDate.Year) && (returnDate.Month == dueDate.Month) && (returnDate.Day <= dueDate.Day));
}

enum HackosFine
{
    DaysFine = 15,
    MonthsFine = 500,
    YearsFine = 10000
}
