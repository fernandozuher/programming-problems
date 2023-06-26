// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        List<int> inputLine = _readAnIntArray();
        int nCities = inputLine.First(), _ = inputLine.Last();

        List<int> citiesWithSpaceStation = _readAnIntArray();
        FlatlandSpaceStations obj = new FlatlandSpaceStations(nCities, citiesWithSpaceStation);
        Console.WriteLine(obj.GetMaxDistanceFromSpaceStation());
    }

        private static List<int> _readAnIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

public class FlatlandSpaceStations
{
    int _nCities;
    List<int> _citiesWithSpaceStation;
    int _maxDistanceFromSpaceStation;

    public FlatlandSpaceStations(int nCities, List<int> citiesWithSpaceStation)
    {
        _nCities = nCities;
        _citiesWithSpaceStation = citiesWithSpaceStation;
        _maxDistanceFromSpaceStation = 0;

        _citiesWithSpaceStation.Sort();
        _findMaxDistanceFromSpaceStation();
    }

        private void _findMaxDistanceFromSpaceStation()
        {
            for (int cityI = 0; cityI < _nCities; cityI++)
            {
                int distance = _findMinDistanceBetweenCityAndNearestSpaceStation(cityI);
                _maxDistanceFromSpaceStation = Math.Max(_maxDistanceFromSpaceStation, distance);
            }
        }

            private int _findMinDistanceBetweenCityAndNearestSpaceStation(int cityI)
            {
                int element = _findElementOrNearest(cityI, _citiesWithSpaceStation);
                int minDistanceBetweenCityAndNearestSpaceStation = Math.Abs(cityI - element);
                return minDistanceBetweenCityAndNearestSpaceStation;
            }

                private int _findElementOrNearest(int n, List<int> array) {
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

    public int GetMaxDistanceFromSpaceStation()
    {
        return _maxDistanceFromSpaceStation;
    }
}
