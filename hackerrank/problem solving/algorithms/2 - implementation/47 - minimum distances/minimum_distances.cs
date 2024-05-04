// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    private static int NO_INDEX = -1;

    static void Main()
    {
        int _ = int.Parse(ReadLine());
        List<int> array = ReadIntArray();
        WriteLine(FindMinimumDistance(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int FindMinimumDistance(List<int> array)
        {
            int minimumDistance = Int32.MaxValue;
            var firstIndexesOfElements = new Dictionary<int, (int firstIndex, int secondIndex)>();

            foreach (int i in Enumerable.Range(0, array.Count))
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

            return minimumDistance != Int32.MaxValue ? minimumDistance : NO_INDEX;
        }
}
