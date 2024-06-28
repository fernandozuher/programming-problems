// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> array = ReadIntArray();
        int k = array.Last();
        array = ReadIntArray();
        array.Sort();
        WriteLine(DivisibleSumPairs(array, k));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        static int DivisibleSumPairs(List<int> array, int k)
        {
            return (from i in Enumerable.Range(0, array.Count - 1)
                from num2 in array[(i + 1)..]
                where array[i] <= num2 && (array[i] + num2) % k == 0
                select i).Count();
        }
}