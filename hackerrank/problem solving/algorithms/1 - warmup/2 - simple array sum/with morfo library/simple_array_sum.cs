// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
Console.WriteLine(SumStdin());

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
int SumStdin() => Reader.ReadLn<int, List<int>>().Sum();
