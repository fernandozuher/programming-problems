// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

using System;
using System.Collections.Generic;

class Solution
{
    public static void Main()
    {
        List<int> array1 = _readAndIntArray();
        List<int> array2 = _readAndIntArray();
        (int, int) result = _compareTriplets(array1, array2);
        Console.WriteLine("{0} {1}", result.Item1, result.Item2);
    }

        private static List<int> _readAndIntArray()
        {
            return Console.ReadLine().Split(" ").Select(int.Parse).ToList();
        }

        private static (int, int) _compareTriplets(List<int> array1, List<int> array2)
        {
            int player1 = 0, player2 = 0;

            foreach (var (val1, val2) in array1.Zip(array2))
                if (val1 > val2)
                    player1++;
                else if (val2 > val1)
                    player2++;

            return (player1, player2);
        }
}
