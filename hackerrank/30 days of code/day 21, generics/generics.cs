// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Printer
{
    public static void Main()
    {
        int _ = int.Parse(Console.ReadLine());
        List<int> intList = Console.ReadLine().Split().Select(int.Parse).ToList();

        _ = int.Parse(Console.ReadLine());
        List<string> stringList = Console.ReadLine().Split().ToList();

        _printArray<Int32>(intList);
        _printArray<String>(stringList);
    }

        private static void _printArray<T>(List<T> list)
        {
            foreach (var x in list)
                Console.WriteLine(x);
        }
}
