// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

using static System.Console;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine() ?? "0");
        var list = InitializeList(n);
        DisplayList(list);
    }

    private static LinkedList<int> InitializeList(int n)
    {
        return new LinkedList<int>([.. Enumerable.Range(0, n).Select(_ => int.Parse(ReadLine() ?? "0"))]);
    }

    private static void DisplayList(LinkedList<int> list)
    {
        foreach (var x in list)
            Write($"{x} ");
    }
}
