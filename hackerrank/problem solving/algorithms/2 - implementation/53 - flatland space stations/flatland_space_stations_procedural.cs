// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

using System;

public class FlatlandSpaceStations
{
    public static void Main()
    {
        List<int> inputLine = _readAnIntArray();
        int nCities = inputLine.First(), _ = inputLine.Last();

        List<int> citiesWithSpaceStation = _readAnIntArray();
        Console.WriteLine(_findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        private static List<int> _readAnIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static int _findMaxDistanceFromSpaceStation(int nCities, List<int> citiesWithSpaceStation)
        {
            citiesWithSpaceStation.Sort();
            const int firstCity = 0;
            int maxDistance = citiesWithSpaceStation.First() - firstCity;

            for (int i = 1, previousCity = citiesWithSpaceStation.First(); i < citiesWithSpaceStation.Count; i++)
            {
                int distance = calculateDistanceBetweenCities(citiesWithSpaceStation[i], previousCity);
                maxDistance = Math.Max(maxDistance, distance);
                previousCity = citiesWithSpaceStation[i];
            }

            int lastCity = nCities - 1;
            int lastCityWithSpaceStation = citiesWithSpaceStation.Last();
            if (!hasLastCitySpaceStation(lastCity, lastCityWithSpaceStation))
            {
                int distance = calculateDistanceOfLastCity(lastCity, lastCityWithSpaceStation);
                maxDistance = Math.Max(maxDistance, distance);
            }

            return maxDistance;
        }

            private static int calculateDistanceBetweenCities(int cityWithSpaceStation, int previousCity)
            {
                return (cityWithSpaceStation - previousCity) / 2;
            }

            private static bool hasLastCitySpaceStation(int lastCity, int lastCityWithSpaceStation)
            {
                return lastCity == lastCityWithSpaceStation;
            }

            private static int calculateDistanceOfLastCity(int lastCity, int lastCityWithSpaceStation)
            {
                return lastCity - lastCityWithSpaceStation;
            }
}
