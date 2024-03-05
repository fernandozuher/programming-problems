// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> list = _readIntArray();
        int n = list.First();
        int nQueries = list.Last();

        List<List<int>> queries = _readQueries(nQueries);
        List<int> result = _dynamicArray(queries, n);
        result.ForEach(Console.WriteLine);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static List<List<int>> _readQueries(int n)
        {
            var queries = new List<List<int>>(n);
            while (n-- > 0)
            {
                var query = _readIntArray();
                queries.Add(query);
            }
            return queries;
        }

        private static List<int> _dynamicArray(List<List<int>> queries, int n)
        {
            List<List<int>> array = _initializeMatrix(n);
            var answers = new List<int>();
            int lastAnswer = 0;

            foreach (var query in queries)
            {
                int type = query[0];
                int x = query[1];
                int y = query[2];

                int index = (x ^ lastAnswer) % n;

                if (type == 1)
                    array[index].Add(y);
                else
                {
                    int j = y % array[index].Count;
                    lastAnswer = array[index][j];
                    answers.Add(lastAnswer);
                }
            }

            return answers;
        }

            private static List<List<int>> _initializeMatrix(int n)
            {
                var list = new List<List<int>>(n);
                for (int i = 0; i < n; ++i)
                    list.Add(new List<int>());
                return list;
            }
}
