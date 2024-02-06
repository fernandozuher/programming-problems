// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> line = _readIntArray();
        int nQueries = line.Last();
        int rotationCount = line[1];
        List<int> array = _readIntArray();
        List<int> queries = _readLines(nQueries);

        var obj = new CircularArrayRotation(array, rotationCount);
        _printArrayAccordingToIndexFromAnotherArray(obj.RotatedArray, queries);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static List<int> _readLines(int n)
        {
            return Enumerable.Range(0, n).Select(_ => int.Parse(Console.ReadLine())).ToList();
        }

        private static void _printArrayAccordingToIndexFromAnotherArray(List<int> array1, List<int> array2)
        {
            array2.ForEach(i => Console.WriteLine(array1[i]));
        }
}

    public class CircularArrayRotation
    {
        private List<int> _array;
        private int _rotationCount;

        public CircularArrayRotation(List<int> array, int rotationCount)
        {
            _array = array;
            _rotationCount = rotationCount;
            _reduceRotations();
            _rotateArray();
        }

            private void _reduceRotations()
            {
                if (_array.Count > 1)
                    _rotationCount = _rotationCount >= _array.Count ? _rotationCount % _array.Count : _rotationCount;
                else
                    _rotationCount = 0;
            }

            private void _rotateArray()
            {
                List<int> firstHalfArray = _array.GetRange(_array.Count - _rotationCount, _rotationCount);
                List<int> secondHalfArray = _array.GetRange(0, _array.Count - _rotationCount);
                _array = firstHalfArray.Concat(secondHalfArray).ToList();
            }

        public List<int> RotatedArray
        {
            get { return _array; }
        }
    }
