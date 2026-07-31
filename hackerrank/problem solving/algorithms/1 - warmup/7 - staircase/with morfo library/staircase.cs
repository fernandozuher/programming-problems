// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
Staircase(n);

// T: O(n^2)
// S: O(n) extra space
void Staircase(int n)
{
    for (int i = 1; i <= n; i++)
    {
        var spaces = new string(' ', n - i);
        var hashes = new string('#', i);
        Console.WriteLine(spaces + hashes);
    }
}
