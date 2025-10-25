// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

const int TransitionYear = 1918;
int year = int.Parse(Console.ReadLine()!);
Console.WriteLine(CalculateDateOf256thDay(year));

string CalculateDateOf256thDay(int year)
{
    int day;
    if (year == TransitionYear)
        day = 26;
    else
        day = IsLeapYear(year) ? 12 : 13;
    return day + ".09." + year;
}

bool IsLeapYear(int year)
{
    if (year < TransitionYear)
        return IsLeapJulianYear(year);
    if (year > TransitionYear)
        return IsLeapGregorianYear(year);
    return false;
}

bool IsLeapJulianYear(int year) => year % 4 == 0;

bool IsLeapGregorianYear(int year) => year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
