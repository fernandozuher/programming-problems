// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

using Morfo.IO;

var (n1, n2) = Reader.Read<int, int>();
Console.WriteLine(SolveMeFirst(n1, n2));

// T: O(1)
// S: O(1) extra space
int SolveMeFirst(int n1, int n2) => n1 + n2;
