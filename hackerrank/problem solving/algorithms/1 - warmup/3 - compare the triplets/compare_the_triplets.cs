// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> array1 = ReadIntArray();
        List<int> array2 = ReadIntArray();
        var (player1, player2) = CompareTriplets(array1, array2);
        WriteLine("{0} {1}", player1, player2);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static (int, int) CompareTriplets(List<int> array1, List<int> array2)
        {
            int player1 = 0, player2 = 0;

            foreach (var (p1, p2) in array1.Zip(array2))
                if (p1 > p2)
                    ++player1;
                else if (p2 > p1)
                    ++player2;

            return (player1, player2);
        }
}
