// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

Console.ReadLine();
long[] arr = ReadNums();
Console.WriteLine(AVeryBigSum(arr));

long[] ReadNums() => Console.ReadLine()!.Split().Select(long.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(1) extra space
long AVeryBigSum(long[] arr) => arr.Sum();
