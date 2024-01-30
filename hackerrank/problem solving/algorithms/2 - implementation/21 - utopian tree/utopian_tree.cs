// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> testCases = _readLines(n);
        var obj = new UtopianTree(testCases);
        obj.TreesHeights.ForEach(x => Console.WriteLine(x));
    }

        private static List<int> _readLines(int n)
        {
            return new List<int>(new int[n]).Select(_ => int.Parse(Console.ReadLine())).ToList();
        }
}

    public class UtopianTree
    {
        private List<int> _testCases;
        private List<int> _treesHeights;

        public UtopianTree(List<int> testCases)
        {
            _testCases = testCases;
            _treesHeights = new List<int>(new int[_testCases.Count]);
            _calculateTreesHeights();
        }

            private void _calculateTreesHeights()
            {
                _treesHeights = _treesHeights.Select((_, i) => _calculateHeight(_testCases[i])).ToList();
            }

                private int _calculateHeight(int cycles)
                {
                    int height = 1;
                    for (int cycle = 1; cycle <= cycles; cycle++)
                        height = _isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
                    return height;
                }

                    private bool _isCycleHappeningDuringSpring(int cycle)
                    {
                        return (cycle & 1) == 1;
                    }

        public List<int> TreesHeights
        {
            get { return _treesHeights; }
        }
    }
