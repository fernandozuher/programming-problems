// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        var line = ReadIntArray();
        int n = line.First();
        int nQueries = line.Last();
        var obj = new DynamicArray(n);

        while (nQueries-- > 0)
            obj.HandleQuery(ReadIntArray());
        obj.Answers.ForEach(Console.WriteLine);
    }

        public static List<int> ReadIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class DynamicArray
    {
        private int _n;
        private List<List<int>> _array;
        private List<int> _answers;
        private int _lastAnswer;

        public DynamicArray(int n)
        {
            _n = n;

            _array = new List<List<int>>(n);
            for (int i = 0; i < n; ++i)
                _array.Add(new List<int>());

            _answers = new List<int>();
            _lastAnswer = 0;
        }

        public void HandleQuery(List<int> query)
        {
            int type = query.First();
            int x = query[1];
            int y = query.Last();

            int index = (x ^ _lastAnswer) % _n;

            if (type == 1)
                _array[index].Add(y);
            else
            {
                int j = y % _array[index].Count;
                _lastAnswer = _array[index][j];
                _answers.Add(_lastAnswer);
            }
        }

        public List<int> Answers
        {
            get { return _answers; }
        }
    }
