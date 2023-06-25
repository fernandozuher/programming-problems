// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

using System;

public class FlatlandSpaceStations
{
    public static void Main()
    {
        List<int> inputLine = _readAnIntArray();
        int nCities = inputLine.First(), _ = inputLine.Last();

        List<int> citiesWithSpaceStation = _readAnIntArray();
        Console.WriteLine(_findMaximumDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        private static List<int> _readAnIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static int _findMaximumDistanceFromSpaceStation(int nCities, List<int> citiesWithSpaceStation)
        {
            int maxDistance = 0;

            citiesWithSpaceStation.Sort();

            for (int cityI = 0; cityI < nCities; cityI++)
            {
                int distance = _findMinDistanceBetweenCityAndNearestSpaceStation(cityI, citiesWithSpaceStation);
                maxDistance = Math.Max(maxDistance, distance);
            }

            return maxDistance;
        }

            private static int _findMinDistanceBetweenCityAndNearestSpaceStation(int cityI, List<int> citiesWithSpaceStation)
            {
                int element = _findElementOrNearest(cityI, citiesWithSpaceStation);
                int minDistanceBetweenCityAndNearestSpaceStation = Math.Abs(cityI - element);
                return minDistanceBetweenCityAndNearestSpaceStation;
            }

                private static int _findElementOrNearest(int n, List<int> array) {
                    int max = array.Count - 1;
                    int min = 0;

                    int minDistance = Int32.MaxValue;
                    int nearestElement = n;

                    while (min <= max) {
                        int mid = (min + max) / 2;

                        int distance = Math.Abs(array[mid] - n);
                        if (distance < minDistance) {
                            nearestElement = array[mid];
                            minDistance = distance;
                        }

                        if (array[mid] == n)
                            return n;
                        else if (array[mid] > n)
                            max = mid - 1;
                        else
                            min = mid + 1;
                    }

                    return nearestElement;
                }
}
