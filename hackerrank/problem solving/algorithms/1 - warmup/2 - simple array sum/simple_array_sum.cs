// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int _n = int.Parse(ReadLine());
        List<int> array = ReadIntArray();
        WriteLine(SimpleArraySum(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int SimpleArraySum(List<int> array)
        {
            return array.Aggregate(0, (a, b) => a + b);
        }
}
