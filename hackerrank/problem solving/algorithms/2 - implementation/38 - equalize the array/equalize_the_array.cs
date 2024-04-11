// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class EqualizeTheArray
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
        Dictionary<int, int> frequency = ReadArrayIntoMap(array);
        Console.WriteLine(EqualizeArray(frequency, n));
    }

        public static Dictionary<int, int> ReadArrayIntoMap(List<int> array)
        {
            var map = new Dictionary<int, int>();
            foreach (var x in array)
            {
                map.TryGetValue(x, out var value);
                map[x] = value + 1;
            }
            return map;
        }

        public static int EqualizeArray(Dictionary<int, int> map, int n)
        {
            int maximumQuantityOfEqualElement = map.Values.Max();
            int minimumNumberRequiredDeletions = n - maximumQuantityOfEqualElement;
            return minimumNumberRequiredDeletions;
        }
}
