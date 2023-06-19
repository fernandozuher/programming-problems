// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int _ = int.Parse(Console.ReadLine());
        List<int> array = _readAnIntArray();
        MinimumDistances obj = new MinimumDistances(array);
        Console.WriteLine(obj.GetMinimumDistance());
    }

        private static List<int> _readAnIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class MinimumDistances
    {
        private static int NO_INDEX = -1;
        private List<int> _array;
        private int _minimumDistance;

        public MinimumDistances(List<int> array)
        {
            _array = array;
            _minimumDistance = Int32.MaxValue;
            _findMinimumDistance();
        }

            private void _findMinimumDistance()
            {
                Dictionary<int, (int firstIndex, int secondIndex)> firstIndexesOfElements = new Dictionary<int, (int firstIndex, int secondIndex)>();

                for (int i = 0; i < _array.Count; i++)
                {
                    int element = _array[i];
                    if (firstIndexesOfElements.ContainsKey(element))
                    {
                        var (firstIndex, secondIndex) = firstIndexesOfElements[element];
                        if (secondIndex == NO_INDEX)
                        {
                            secondIndex = i;
                            firstIndexesOfElements[element] = (firstIndex, secondIndex);
                            int minimumDistanceOfCurrentElement = secondIndex - firstIndex;
                            _minimumDistance = Math.Min(_minimumDistance, minimumDistanceOfCurrentElement);
                        }
                    }
                    else
                        firstIndexesOfElements.Add(element, (i, NO_INDEX));
                }

                _minimumDistance = _minimumDistanceOrNoIndex();
            }

                private int _minimumDistanceOrNoIndex()
                {
                    return _minimumDistance != Int32.MaxValue ? _minimumDistance : NO_INDEX;
                }

        public int GetMinimumDistance()
        {
            return _minimumDistance;
        }
    }
