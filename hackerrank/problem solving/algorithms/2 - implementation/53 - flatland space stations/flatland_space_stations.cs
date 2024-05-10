// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

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
                const int firstCity = 0;
                _maxDistanceFromSpaceStation = _citiesWithSpaceStation.First() - firstCity;

                for (int i = 1, previousCity = _citiesWithSpaceStation.First(); i < _citiesWithSpaceStation.Count; i++)
                {
                    int distance = _calculateDistanceBetweenCities(_citiesWithSpaceStation[i], previousCity);
                    _maxDistanceFromSpaceStation = Math.Max(_maxDistanceFromSpaceStation, distance);
                    previousCity = _citiesWithSpaceStation[i];
                }

                if (!_hasLastCitySpaceStation())
                {
                    int distance = _calculateDistanceOfLastCity();
                    _maxDistanceFromSpaceStation = Math.Max(_maxDistanceFromSpaceStation, distance);
                }
            }

                private int _calculateDistanceBetweenCities(int cityWithSpaceStation, int previousCity)
                {
                    return (cityWithSpaceStation - previousCity) / 2;
                }

                private bool _hasLastCitySpaceStation()
                {
                    return _nCities-1 == _citiesWithSpaceStation.Last();
                }

                private int _calculateDistanceOfLastCity()
                {
                    return _nCities-1 - _citiesWithSpaceStation.Last();
                }

        public int GetMaxDistanceFromSpaceStation()
        {
            return _maxDistanceFromSpaceStation;
        }
    }
