// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = ReadLine();
        array.Sort();

        var obj = new CutTheSticks(array);
        obj.RemainingSticksLengthArray.ForEach(Console.WriteLine);
    }

    private static List<int> ReadLine()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToList();
    }
}

    public class CutTheSticks
    {
        private List<int> _sticksLengthArray;
        private List<int> _remainingSticksLengthArray;

        public CutTheSticks(List<int> array)
        {
            _sticksLengthArray = array;
            _remainingSticksLengthArray = new List<int> {array.Count};
            _cutTheSticks();
        }

            private void _cutTheSticks()
            {
                for (int i = 0, n = _sticksLengthArray.Count; i < n;)
                {
                    int shortestStickLength = _sticksLengthArray[i];

                    i = _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, n);
                    int currentIterationSize = n - i;
                    if (i == n)
                        break;

                    _remainingSticksLengthArray.Add(currentIterationSize);
                    _decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, n, shortestStickLength);
                }
            }

                private int _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index, int n)
                {
                    int shortestStickLength = _sticksLengthArray[index];
                    while (index < n && _sticksLengthArray[index] == shortestStickLength)
                        ++index;
                    return index;
                }

                private void _decreaseSticksLengthsHigherThanCurrentShortestStickLength(int index, int n, int shortestStickLength)
                {
                    for (int i = index; i < n; ++i)
                        _sticksLengthArray[i] -= shortestStickLength;
                }

        public List<int> RemainingSticksLengthArray
        {
            get { return _remainingSticksLengthArray; }
        }
    }
