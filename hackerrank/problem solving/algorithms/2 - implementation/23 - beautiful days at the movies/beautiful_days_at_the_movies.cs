// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

var (startDay, endDay, divisor) = ReadInput();
Console.WriteLine(BeautifulDays(startDay, endDay, divisor));

(int, int, int) ReadInput()
{
    var values = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    return (values[0], values[1], values[2]);
}

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int BeautifulDays(int startDay, int endDay, int divisor)
{
    return Enumerable.Range(startDay, endDay - startDay + 1).Count(day => IsDayBeautiful(day, divisor));
}

bool IsDayBeautiful(int day, int divisor)
{
    return (day - ReverseNumber(day)) % divisor == 0;
}

int ReverseNumber(int number)
{
    return int.Parse(new string(number.ToString().Reverse().ToArray()));
}
