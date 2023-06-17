// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

using System;

public class MinimumDistances
{
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
            Dictionary<int, (int firstIndex, int secondIndex)> elements = new Dictionary<int, (int firstIndex, int secondIndex)>();

            for (int i = 0, element; i < array.Count; i++)
            {
                element = array[i];
                if (elements.ContainsKey(element))
                {
                    if (elements[element].secondIndex == -1)
                    {
                        int secondIndex = i;
                        elements[element] = (elements[element].firstIndex, secondIndex);
                        int minimumDistanceOfCurrentElement = elements[element].secondIndex - elements[element].firstIndex;
                        minimumDistance = Math.Min(minimumDistance, minimumDistanceOfCurrentElement);
                    }
                }
                else
                    elements.Add(element, (i, -1));
            }

            return minimumDistance != Int32.MaxValue ? minimumDistance : -1;
        }
}
