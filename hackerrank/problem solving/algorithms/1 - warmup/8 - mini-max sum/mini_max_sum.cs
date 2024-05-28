// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> array = ReadIntArray();
        array.Sort();
        var (minSum, maxSum) = MiniMaxSum(array);
        WriteLine("{0} {1}", minSum, maxSum);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static (long, long) MiniMaxSum(List<int> array)
        {
            long sum = array.Aggregate(0L, (a, b) => a + b);
            long minSum = sum - array.Last();
            long maxSum = sum - array.First();
            return (minSum, maxSum);
        }
}
