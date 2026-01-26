// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

string s1 = Console.ReadLine()!;
string s2 = Console.ReadLine()!;
int nOps = int.Parse(Console.ReadLine()!);
Console.WriteLine(AppendAndDelete(s1, s2, nOps) ? "Yes" : "No");

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
bool AppendAndDelete(string s1, string s2, int nOps)
{
    int prefixLen = CommonPrefixLength(s1, s2);
    int opsNeeded = (s1.Length - prefixLen) + (s2.Length - prefixLen);
    if (nOps < opsNeeded)
        return false;

    if (nOps >= s1.Length + s2.Length)
        return true;

    return (nOps - opsNeeded) % 2 == 0;
}

int CommonPrefixLength(string s1, string s2)
{
    int minLen = Math.Min(s1.Length, s2.Length);
    return Enumerable.Range(0, minLen).FirstOrDefault(i => s1[i] != s2[i], minLen);
}
