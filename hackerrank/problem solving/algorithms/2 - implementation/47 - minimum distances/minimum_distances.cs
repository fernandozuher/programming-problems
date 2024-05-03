// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

using System;

public class MinimumDistances
{
    private static int NO_INDEX = -1;
    public static void Main()
    {
        int _ = int.Parse(Console.ReadLine());
        List<int> array = _readAnIntArray();
        Console.WriteLine(_findMinimumDistance(array));
    }

        private static List<int> _readAnIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static int _findMinimumDistance(List<int> array)
        {
            int minimumDistance = Int32.MaxValue;
            Dictionary<int, (int firstIndex, int secondIndex)> firstIndexesOfElements = new Dictionary<int, (int firstIndex, int secondIndex)>();

            for (int i = 0; i < array.Count; i++)
            {
                int element = array[i];
                if (firstIndexesOfElements.ContainsKey(element))
                {
                    var (firstIndex, secondIndex) = firstIndexesOfElements[element];
                    if (secondIndex == NO_INDEX)
                    {
                        secondIndex = i;
                        firstIndexesOfElements[element] = (firstIndex, secondIndex);
                        int minimumDistanceOfCurrentElement = secondIndex - firstIndex;
                        minimumDistance = Math.Min(minimumDistance, minimumDistanceOfCurrentElement);
                    }
                }
                else
                    firstIndexesOfElements.Add(element, (i, NO_INDEX));
            }

            return _minimumDistanceOrNoIndex(minimumDistance);
        }

            private static int _minimumDistanceOrNoIndex(int minimumDistance)
            {
                return minimumDistance != Int32.MaxValue ? minimumDistance : NO_INDEX;
            }
}
