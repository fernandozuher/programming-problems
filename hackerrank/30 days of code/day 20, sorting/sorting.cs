// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int _ = int.Parse(Console.ReadLine());
        List<int> list = Console.ReadLine().Split().Select(int.Parse).ToList();

        Console.WriteLine("Array is sorted in {0} swaps.", _bubbleSort(list));
        Console.WriteLine("First Element: {0}", list.First());
        Console.WriteLine("Last Element: {0}", list.Last());
    }

        private static int _bubbleSort(List<int> a)
        {
            int numberOfSwaps = 0;

            for (int n = a.Count - 1; n > 0; --n)
            {
                for (int i = 0; i < n; ++i)
                    if (a[i] > a[i + 1]) {
                        _swap(a, i);
                        ++numberOfSwaps;
                    }

                if (numberOfSwaps == 0)
                    break;
            }

            return numberOfSwaps;
        }

            private static void _swap(List<int> a, int i)
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
}
