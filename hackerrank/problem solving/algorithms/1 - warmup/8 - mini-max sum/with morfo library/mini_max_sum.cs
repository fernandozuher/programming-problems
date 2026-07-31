// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

using Morfo.IO;

var arr = Reader.ReadLn<int, int[]>();
var (minSum, maxSum) = CalcMinMaxSum(arr);
Console.WriteLine("{0} {1}", minSum, maxSum);

// n: length of arr
// T: O(n)
// S: O(1) extra space
(long, long) CalcMinMaxSum(int[] arr)
{
    long total, minValue, maxValue;
    total = minValue = maxValue = arr[0];

    foreach (var x in arr.Skip(1))
    {
        total += x;
        minValue = Math.Min(x, minValue);
        maxValue = Math.Max(x, maxValue);
    }

    return (total - maxValue, total - minValue);
}
