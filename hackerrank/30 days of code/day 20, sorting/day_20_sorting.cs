using System.Collections.Generic;
using System.Linq;
using System;

class Solution
{
    static int bubbleSort(List<int> a)
    {        
        int numberOfSwaps = 0;

        for (int i = 0, N = a.Count; i < N; i++) {

            for (int j = 0, N2 = N - 1; j < N2; j++)

                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    numberOfSwaps++;
                }

            if (numberOfSwaps == 0)
                break;
        }
        return numberOfSwaps;
    }

    static void Main(string[] args)
    {
        Console.ReadLine();

        List<int> list = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(value => Convert.ToInt32(value)).ToList();

        Console.WriteLine("Array is sorted in {0} swaps.", bubbleSort(list));
        Console.WriteLine("First Element: {0}", list.First());
        Console.WriteLine("Last Element: {0}", list.Last());
    }
}
