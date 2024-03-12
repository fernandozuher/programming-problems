// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        ConcurrentDictionary<string, int> input = ReadInput(n);

        n = int.Parse(Console.ReadLine());
        List<int> result = ReadQueriesAndCountMatches(input, n);
        result.ForEach(Console.WriteLine);
    }

        public static ConcurrentDictionary<string, int> ReadInput(int n)
        {
            var input = new ConcurrentDictionary<string, int>();
            while (n-- > 0)
            {
                string x = Console.ReadLine();
                input.AddOrUpdate(x, 1, (k, v) => v + 1);
            }
            return input;
        }

        public static List<int> ReadQueriesAndCountMatches(ConcurrentDictionary<string, int> input, int n)
        {
            var result = new List<int>(n);
            while (n-- > 0)
            {
                string query = Console.ReadLine();
                int count = input.ContainsKey(query) ? input[query] : 0;
                result.Add(count);
            }
            return result;
        }
}
