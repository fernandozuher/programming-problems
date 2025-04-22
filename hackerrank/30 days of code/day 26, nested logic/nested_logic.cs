// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        DateTime returnedRealDate = ReadDate();
        DateTime dueDate = ReadDate();
        if (returnedRealDate <= dueDate)
            WriteLine(0);
        else
            WriteLine(new FineOnDelay(returnedRealDate, dueDate).Fine);
    }

    private static DateTime ReadDate()
    {
        var dateParts = ReadLine().Split(" ").Select(int.Parse).ToArray();
        int day = dateParts[0], month = dateParts[1], year = dateParts[2];
        return new DateTime(year, month, day);
    }
}

public class FineOnDelay
{
    private static readonly int _finePerYear = 10000;
    private static readonly int _finePerMonth = 500;
    private static readonly int _finePerDay = 15;

    private readonly DateTime _returnedRealDate;
    private readonly DateTime _dueDate;
    public int Fine { get; }

    public FineOnDelay(DateTime returnedRealDate, DateTime dueDate)
    {
        _returnedRealDate = returnedRealDate;
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
        if (_returnedRealDate.Year > _dueDate.Year)
            return _finePerYear;
        return 0;
    }

    private int LateByMonth()
    {
        if (_returnedRealDate.Year == _dueDate.Year && _returnedRealDate.Month > _dueDate.Month)
            return (_returnedRealDate.Month - _dueDate.Month) * _finePerMonth;
        return 0;
    }

    private int LateByDay()
    {
        if (_returnedRealDate.Year == _dueDate.Year && _returnedRealDate.Month == _dueDate.Month && _returnedRealDate.Day > _dueDate.Day)
            return (_returnedRealDate.Day - _dueDate.Day) * _finePerDay;
        return 0;
    }
}
