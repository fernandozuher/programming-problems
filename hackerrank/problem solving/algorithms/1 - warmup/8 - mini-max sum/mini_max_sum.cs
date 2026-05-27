// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

int[] arr = ReadNumbers();
var (minSum, maxSum) = CalcMinMaxSum(arr);
Console.WriteLine("{0} {1}", minSum, maxSum);

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(1) extra space
(long, long) CalcMinMaxSum(int[] arr)
{
    long sum, min, max;
    sum = min = max = arr[0];

    foreach (var x in arr.Skip(1))
    {
        sum += x;
        min = Math.Min(x, min);
        max = Math.Max(x, max);
    }

    return (sum - max, sum - min);
}
