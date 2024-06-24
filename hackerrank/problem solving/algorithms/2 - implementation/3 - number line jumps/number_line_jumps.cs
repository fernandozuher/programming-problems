// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> array = ReadIntArray();
        WriteLine(Kangaroo(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static string Kangaroo(List<int> array)
        {
            int x1 = array.First();
            int v1 = array[1];
            int x2 = array[2];
            int v2 = array.Last();

            if (v2 >= v1)
                return "NO";
            for (; x1 < x2; x1 += v1, x2 += v2);
            return x1 == x2 ? "YES" : "NO";
        }
}
