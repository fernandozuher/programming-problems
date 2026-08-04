// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
long[] arr = Reader.ReadLn<long, long[]>();
Console.WriteLine(AVeryBigSum(arr));

// n: length of arr
// T: O(n)
// S: O(1) extra space
long AVeryBigSum(long[] arr) => arr.Sum();
