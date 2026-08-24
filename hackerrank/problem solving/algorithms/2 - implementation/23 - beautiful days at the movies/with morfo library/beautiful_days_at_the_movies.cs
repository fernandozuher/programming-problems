// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

using Morfo.IO;

var (startDay, endDay, divisor) = Reader.Read<int, int, int>();
Console.WriteLine(BeautifulDays(startDay, endDay, divisor));

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int BeautifulDays(int startDay, int endDay, int divisor)
{
    return Enumerable.Range(startDay, endDay - startDay + 1).Count(day => IsBeautifulDay(day, divisor));
}

bool IsBeautifulDay(int day, int divisor) => (day - ReverseNumber(day)) % divisor == 0;

int ReverseNumber(int number) => int.Parse(new string(number.ToString().Reverse().ToArray()));
