// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        int nTestCases = ReadLineAsInt();
        List<int> nTestCasesCycles = ReadCycles(nTestCases);
        Result result = new Result(nTestCasesCycles);
    }

    private static int ReadLineAsInt()
    {
        return int.Parse(Console.ReadLine());
    }

    private static List<int> ReadCycles(int nTestCases)
    {
        List<int> nTestCasesCycles = new List<int>(new int[nTestCases]).Select(_ => ReadLineAsInt()).ToList();
        return nTestCasesCycles;
    }
}

    class Result
    {
        private List<int> _nTestCasesCycles;
        private List<int> _treesHeights;

        public Result(List<int> nTestCasesCycles)
        {
            _nTestCasesCycles = nTestCasesCycles;
            _treesHeights = new List<int>(new int[_nTestCasesCycles.Count]);

            _UtopianTree();
            PrintResult();
        }

            private void _UtopianTree()
            {
                int i = 0;
                _treesHeights = _treesHeights.Select(_ => _CalculateHeight(_nTestCasesCycles[i++])).ToList();
            }

                private int _CalculateHeight(int cycles)
                {
                    int height = 1;

                    for (int cycle = 1; cycle <= cycles; cycle++)
                        height = _IsCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;

                    return height;
                }

                    private bool _IsCycleHappeningDuringSpring(int cycle)
                    {
                        return (cycle & 1) == 1;
                    }

            public void PrintResult()
            {
                _treesHeights.ForEach(Console.WriteLine);
            }
    }
