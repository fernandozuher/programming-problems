using System;

class Result
{
    /*
     * Complete the 'miniMaxSum' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void miniMaxSum(List<int> arr)
    {
        arr.Sort();
        long totalSum = arr.Aggregate(0L, (sum, num) => sum + num);
        long minSum = totalSum - arr.Last();
        long maxSum = totalSum - arr.First();
        Console.WriteLine("{0} {1}", minSum, maxSum);
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();
        Result.miniMaxSum(arr);
    }
}
