// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

using static System.Console;

static class Solution
{
    static void Main()
    {
        LinkedList<int> l = ReadList();
        RemoveDuplicates(l);
        Display(l);
    }

    private static LinkedList<int> ReadList()
    {
        int n = int.Parse(ReadLine());
        return new LinkedList<int>(Enumerable.Range(0, n).Select(_ => int.Parse(ReadLine())));
    }

    private static void RemoveDuplicates(LinkedList<int> list)
    {
        var seen = new HashSet<int>();
        var current = list.First;
        while (current != null)
        {
            var next = current.Next;
            if (seen.Contains(current.Value))
                list.Remove(current);
            else
                seen.Add(current.Value);
            current = next;
        }
    }

    private static void Display(LinkedList<int> l)
    {
        foreach (var x in l)
            Write(x + " ");
    }
}
