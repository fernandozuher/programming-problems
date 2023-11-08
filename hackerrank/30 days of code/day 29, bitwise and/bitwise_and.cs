// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        while (n-- > 0)
        {
            List<int> input = Console.ReadLine().Split().Select(int.Parse).ToList();
            int count = input.First();
            int lim = input.Last();
            Console.WriteLine(_bitwiseAnd(count, lim));
        }
    }

        private static int _bitwiseAnd(int n, int k)
        {
            int maximumValueLessThanK = 0;

            for (int i = 1; i <= n; ++i)
                for (int j = i + 1, operation; j <= n; ++j) {
                    operation = i & j;

                    if (operation < k && operation > maximumValueLessThanK) {
                        if (operation == k - 1)
                            return operation;
                        else
                            maximumValueLessThanK = operation;
                    }
                }

            return maximumValueLessThanK;
        }
}
