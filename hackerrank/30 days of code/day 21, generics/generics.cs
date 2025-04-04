// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        List<int> numbers = ReadInput<int>();
        List<string> strings = ReadInput<string>();
        PrintList<int>(numbers);
        PrintList<string>(strings);
    }

    private static List<T> ReadInput<T>()
    {
        int n = int.Parse(ReadLine());
        return Enumerable.Range(0, n)
                         .Select(_ => ReadLine())
                         .Select(x => (T)Convert.ChangeType(x, typeof(T)))
                         .ToList();
    }

    private static void PrintList<T>(List<T> l)
    {
        WriteLine(string.Join("\n", l));
    }
}
