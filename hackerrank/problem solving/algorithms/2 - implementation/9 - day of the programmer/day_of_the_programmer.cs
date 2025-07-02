// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

class Solution
{
    public static void Main()
    {
        int year = int.Parse(Console.ReadLine()!);
        Console.WriteLine(DayOfTheProgrammer.CalculateDateOf256thDay(year));
    }
}

class DayOfTheProgrammer
{
    private const int TransitionYear = 1918;

    public static string CalculateDateOf256thDay(int year)
    {
        string day;
        if (year == TransitionYear)
            day = "26";
        else
            day = IsLeapYear(year) ? "12" : "13";
        return day + ".09." + year.ToString();
    }

    private static bool IsLeapYear(int year)
    {
        if (year < TransitionYear)
            return IsLeapJulianYear(year);
        if (year > TransitionYear)
            return IsLeapGregorianYear(year);
        return false;
    }

    private static bool IsLeapJulianYear(int year) => year % 4 == 0;

    private static bool IsLeapGregorianYear(int year) => year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
