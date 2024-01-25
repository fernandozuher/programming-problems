// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        array.Sort();

        var obj = new PickingNumbers(array);
        Console.WriteLine(obj.SubarrayBiggestSize);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class PickingNumbers
    {
        private List<int> _numbers;
        private int _subarrayBiggestSize;

        public PickingNumbers(List<int> numbers)
        {
            _numbers = numbers;
            _subarrayBiggestSize = 1;
            _pickingNumbers();
        }

            private void _pickingNumbers()
            {
                int firstReferenceNumberIndex = 0;
                int secondReferenceNumberIndex = 0;
                int subarrayCurrentSize = 1;

                for (int i = 1, n = _numbers.Count; i < n; ++i) {
                    int difference = _numbers[i] - _numbers[firstReferenceNumberIndex];

                    switch (difference) {
                    case 0:
                        ++subarrayCurrentSize;
                        break;

                    case 1:
                        ++subarrayCurrentSize;
                        if (_numbers[secondReferenceNumberIndex] != _numbers[i])
                            secondReferenceNumberIndex = i;
                        break;

                    default:
                        _subarrayBiggestSize = _updateSubarrayBiggestSize(subarrayCurrentSize);
                        List<int> update = _updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                        firstReferenceNumberIndex = update.First();
                        secondReferenceNumberIndex = i;
                        subarrayCurrentSize = update.Last();
                        break;
                    }
                }

                _subarrayBiggestSize = _updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                int _updateSubarrayBiggestSize(int subarrayCurrentSize)
                {
                    return Math.Max(subarrayCurrentSize, _subarrayBiggestSize);
                }

                List<int> _updateFirstReferenceNumberIndexAndSubarrayCurrentSize(int i, int secondReferenceNumberIndex)
                {
                    int firstReferenceNumberIndex, subarrayCurrentSize;

                    if (_numbers[i] - _numbers[secondReferenceNumberIndex] == 1)
                    {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    }
                    else
                    {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    return new List<int>() {firstReferenceNumberIndex, subarrayCurrentSize};
                }

        public int SubarrayBiggestSize
        {
            get { return _subarrayBiggestSize; }
        }
    }
