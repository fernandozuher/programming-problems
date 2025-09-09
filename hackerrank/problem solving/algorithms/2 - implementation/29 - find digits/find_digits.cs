// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = ReadNumber();
        Enumerable.Range(0, n)
        .Select(_ => FindDigits(ReadNumber()))
        .ToList()
        .ForEach(Console.WriteLine);
    }

    private static int ReadNumber()
    {
        return int.Parse(Console.ReadLine()!);
    }

    private static int FindDigits(int n)
    {
        return n.ToString().ToCharArray().Select(c => c - '0').Count(d => d != 0 && n % d == 0);
    }
}
