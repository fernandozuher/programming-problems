// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()); // Not used
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();

        Difference difference = new Difference(array);
        difference.ComputeDifference();
        Console.WriteLine(difference.MaximumDifference);
    }
}

    class Difference
    {
        private List<int> _elements;
        public int MaximumDifference;

        public Difference(List<int> elements)
        {
            _elements = elements;
        }

        public void ComputeDifference()
        {
            _elements.Sort();
            MaximumDifference = _elements.Last() - _elements.First();
        }
    }
