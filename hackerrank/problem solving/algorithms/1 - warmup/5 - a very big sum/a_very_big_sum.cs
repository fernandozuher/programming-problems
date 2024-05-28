// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int _n = int.Parse(ReadLine());
        List<int> array = ReadIntArray();
        WriteLine(AVeryBigSum(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static long AVeryBigSum(List<int> array)
        {
            return array.Aggregate(0L, (a, b) => a + b);
        }
}
