// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

using static System.Console;

static class Solution
{
    static void Main()
    {
        LinkedList<int> dataList = ReadList();
        RemoveDuplicates(dataList);
        Display(dataList);
    }

    private static LinkedList<int> ReadList()
    {
        int n = int.Parse(ReadLine());
        return new LinkedList<int>(Enumerable.Range(0, n).Select(_ => int.Parse(ReadLine())));
    }

    private static void RemoveDuplicates(LinkedList<int> dataList)
    {
        var seen = new HashSet<int>();
        var current = dataList.First;
        while (current != null)
        {
            var next = current.Next;
            if (seen.Contains(current.Value))
                dataList.Remove(current);
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
