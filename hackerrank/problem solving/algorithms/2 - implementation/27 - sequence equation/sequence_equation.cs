// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        var obj = new Sequence_Equation(array);
        obj.PermutatedArray.ForEach(Console.WriteLine);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class Sequence_Equation
    {
        List<int> _array;
        List<int> _elementsPositionsArray;
        List<int> _permutatedArray;

        public Sequence_Equation(List<int> array)
        {
            _array = array;
            _elementsPositionsArray = new List<int>(new int[array.Count]);
            _permutatedArray = new List<int>(new int[array.Count]);
            _generateElementsPositionsArray();
            _generatePermutatedArray();
        }

            private void _generateElementsPositionsArray()
            {
                int i = 0;
                foreach (var x in _array)
                    _elementsPositionsArray[x - 1] = i++;
            }

            private void _generatePermutatedArray()
            {
                int i = 0;
                foreach (var x in _elementsPositionsArray)
                    _permutatedArray[i++] = _elementsPositionsArray[x] + 1;
            }

        public List<int> PermutatedArray
        {
            get { return _permutatedArray; }
        }
    }
