// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        string initialString = Console.ReadLine()!;
        string finalString = Console.ReadLine()!;
        int nOperations = int.Parse(Console.ReadLine()!);
        Console.WriteLine(AppendAndDelete(initialString, finalString, nOperations) ? "Yes" : "No");
    }

    private static bool AppendAndDelete(string s1, string s2, int nOps)
    {
        int prefixLen = CommonPrefixLength(s1, s2);
        int totalOpsNeeded = (s1.Length - prefixLen) + (s2.Length - prefixLen);
        bool canRemoveAll = nOps >= s1.Length + s2.Length;
        return canRemoveAll || (nOps >= totalOpsNeeded && (nOps - totalOpsNeeded) % 2 == 0);
    }

    private static int CommonPrefixLength(string s1, string s2)
    {
        int minLen = Math.Min(s1.Length, s2.Length);
        for (int i = 0; i < minLen; i++)
            if (s1[i] != s2[i])
                return i;
        return minLen;
    }
}
