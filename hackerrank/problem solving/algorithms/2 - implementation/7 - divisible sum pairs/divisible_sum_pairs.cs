// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        List<int> array = _readIntArray();
        int k = array[1];
        array = _readIntArray();

        array.Sort();

        var obj = new SubarrayDivision(array, k);
        Console.WriteLine(obj.NDivisibleSumPairs());
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class SubarrayDivision
    {
        private List<int> _array;
        private int _k;
        private int _nDivisible;

        public SubarrayDivision(List<int> array, int k)
        {
            _array = array;
            _k = k;
            _nDivisible = 0;

            _divisibleSumPairs();
        }

            private void _divisibleSumPairs()
            {
                for (int i = 0, n2 = _array.Count - 1; i < n2; ++i)
                    for (int j = i + 1; j < _array.Count; ++j)
                        if (_array[i] <= _array[j] && (_array[i] + _array[j]) % _k == 0)
                            ++_nDivisible;
            }

        public int NDivisibleSumPairs()
        {
            return _nDivisible;
        }
    }
