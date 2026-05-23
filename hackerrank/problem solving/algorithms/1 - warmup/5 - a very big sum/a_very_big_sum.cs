// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

Console.ReadLine();
long[] arr = ReadNumbers();
Console.WriteLine(AVeryBigSum(arr));

long[] ReadNumbers() => Console.ReadLine()!.Split().Select(long.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(1) extra space
long AVeryBigSum(long[] arr) => arr.Sum();
