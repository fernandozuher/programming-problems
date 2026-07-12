// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(SumStdin());

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
int SumStdin() => Console.ReadLine()!.Split().Select(int.Parse).Sum();
