// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        DateTime returnedDate = ReadDate();
        DateTime dueDate = ReadDate();
        int fine = returnedDate <= dueDate ? 0 : (new FineOnDelay(returnedDate, dueDate).Fine);
        Console.WriteLine(fine);
    }

    private static DateTime ReadDate()
    {
        var dateParts = Console.ReadLine().Split(" ").Select(int.Parse).ToArray();
        int day = dateParts[0], month = dateParts[1], year = dateParts[2];
        return new DateTime(year, month, day);
    }
}

public class FineOnDelay
{
    private static readonly int s_finePerYear = 10000;
    private static readonly int s_finePerMonth = 500;
    private static readonly int s_finePerDay = 15;

    private readonly DateTime _returnedDate;
    private readonly DateTime _dueDate;
    public int Fine { get; }

    public FineOnDelay(DateTime returnedDate, DateTime dueDate)
    {
        _returnedDate = returnedDate;
        _dueDate = dueDate;
        Fine = CalculateFine();
    }

    private int CalculateFine()
    {
        int fine = LateByYear();
        if (fine != 0)
            return fine;

        fine = LateByMonth();
        if (fine != 0)
            return fine;

        return LateByDay();
    }

    private int LateByYear()
    {
        if (_returnedDate.Year > _dueDate.Year)
            return s_finePerYear;
        return 0;
    }

    private int LateByMonth()
    {
        if (IsSameYear() && _returnedDate.Month > _dueDate.Month)
            return (_returnedDate.Month - _dueDate.Month) * s_finePerMonth;
        return 0;
    }

    private bool IsSameYear()
    {
        return _returnedDate.Year == _dueDate.Year;
    }

    private int LateByDay()
    {
        if (IsSameYear() && IsSameMonth() && _returnedDate.Day > _dueDate.Day)
            return (_returnedDate.Day - _dueDate.Day) * s_finePerDay;
        return 0;
    }

    private bool IsSameMonth()
    {
        return _returnedDate.Month == _dueDate.Month;
    }
}
