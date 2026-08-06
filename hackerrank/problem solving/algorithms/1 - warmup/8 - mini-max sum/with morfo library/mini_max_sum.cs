// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

using Morfo.Collections;
using Morfo.IO;

var arr = Reader.ReadLn<long, long[]>();
var (minSum, maxSum) = CalcMinMaxSum(arr);
Console.WriteLine("{0} {1}", minSum, maxSum);

// n: length of arr
// T: O(n)
// S: O(1) extra space
(long, long) CalcMinMaxSum(long[] arr)
{
    var (total, minValue, maxValue) = arr.AggregateMany(
        Add, 0L,
        Math.Min, arr[0],
        Math.Max, arr[0]
    );

    return (total - maxValue, total - minValue);
}

long Add(long a, long b) => a + b;
