// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

var arr = ReadNumbers();
int startDay = arr[0];
int endDay = arr[1];
int divisor = arr[2];
Console.WriteLine(BeautifulDays(startDay, endDay, divisor));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int BeautifulDays(int startDay, int endDay, int divisor)
{
    return Enumerable.Range(startDay, endDay - startDay + 1).Count(day => IsDayBeautiful(day, divisor));
}

bool IsDayBeautiful(int day, int divisor)
{
    return Math.Abs(day - ReverseNumber(day)) % divisor == 0;
}

int ReverseNumber(int number)
{
    return int.Parse(new string(number.ToString().Reverse().ToArray()));
}
