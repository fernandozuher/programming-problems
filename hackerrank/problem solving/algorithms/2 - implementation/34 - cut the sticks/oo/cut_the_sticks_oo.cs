// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int _size = _ReadANumber();
        List<int> array = _ReadAnArray();
        array.Sort();

        CutTheSticks obj = new CutTheSticks(array);
        List<int> result = obj.GetRemainingSticksLengthArray();
        printArray(result);
    }

        private static int _ReadANumber()
        {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static List<int> _ReadAnArray()
        {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }

        public static void printArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }

}

    public class CutTheSticks
    {
        private List<int> _SticksLengthArray;
        private int _SizeSticksLengthArray;
        private List<int> _RemainingSticksLengthArray;

        public CutTheSticks(List<int> array)
        {
            _SticksLengthArray = array;
            _SizeSticksLengthArray = array.Count;
            _InitializeRemainingSticksLengthArray();
            _CutTheSticks();
        }

            private void _InitializeRemainingSticksLengthArray()
            {
                _RemainingSticksLengthArray = new List<int> {_SizeSticksLengthArray};
            }

            private void _CutTheSticks()
            {
                for (int i = 0; i < _SizeSticksLengthArray; )
                {
                    int shortestStickLength = _SticksLengthArray[i];

                    i = _FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i);
                    int currentIterationSize = _SizeSticksLengthArray - i;
                    if (i == _SizeSticksLengthArray)
                        break;

                    _RemainingSticksLengthArray.Add(currentIterationSize);
                    _DecreaseSticksLengthsHigherThanCurrentShortestStickLength(i, shortestStickLength);
                }
            }

                private int _FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index)
                {
                    int shortestStickLength = _SticksLengthArray[index];
                    while (index < _SizeSticksLengthArray && _SticksLengthArray[index] == shortestStickLength)
                        index++;
                    return index;
                }

                private void _DecreaseSticksLengthsHigherThanCurrentShortestStickLength(int index, int shortestStickLength)
                {
                    _SticksLengthArray = _SticksLengthArray.Select(element => element - shortestStickLength).ToList();
                }

        public List<int> GetRemainingSticksLengthArray()
        {
            return _RemainingSticksLengthArray;
        }
    }
