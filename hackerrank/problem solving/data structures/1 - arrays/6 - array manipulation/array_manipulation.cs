// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> line = ReadIntArray();
        int n = line.First();
        int nQueries = line.Last();
        Console.WriteLine(ArrayManipulation(n, nQueries));
    }

        public static List<int> ReadIntArray()
        {
            return Console.ReadLine().Split(" ").Select(int.Parse).ToList();
        }

        public static long ArrayManipulation(int n, int nQueries)
        {
            // n + 2 = 1-indexed array + range-end
            var array = new List<int>(Enumerable.Repeat(0, n + 2));

            while (nQueries-- > 0)
            {
                List<int> line = ReadIntArray();
                int b = line.First();
                int e = line[1];
                int summand = line.Last();

                array[b] += summand;
                array[e + 1] -= summand;
            }

            long sum = 0, max = 0;
            foreach (int x in array)
            {
                if (x == 0)
                    continue;
                sum += x;
                max = Math.Max(max, sum);
            }

            return max;
        }
}
