// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// From C# 8.0

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> inputLine = ReadIntArray();
        int nCities = inputLine.First(), _ = inputLine.Last();
        List<int> citiesWithSpaceStation = ReadIntArray();
        citiesWithSpaceStation.Sort();
        WriteLine(FindMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int FindMaxDistanceFromSpaceStation(int nCities, List<int> citiesWithSpaceStation)
        {
            int maxDistanceFromSpaceStation, previousCity;
            maxDistanceFromSpaceStation = previousCity = citiesWithSpaceStation.First();
            foreach (int cityWithSpaceStation in citiesWithSpaceStation.Skip(1))
            {
                int distanceBetweenCities = (cityWithSpaceStation - previousCity) / 2;
                maxDistanceFromSpaceStation = Math.Max(maxDistanceFromSpaceStation, distanceBetweenCities);
                previousCity = cityWithSpaceStation;
            }

            if ((nCities - 1 == citiesWithSpaceStation.Last()) is var hasLastCitySpaceStation && !hasLastCitySpaceStation)
            {
                int distanceOfLastCity = nCities - 1 - citiesWithSpaceStation.Last();
                maxDistanceFromSpaceStation = Math.Max(maxDistanceFromSpaceStation, distanceOfLastCity);
            }

            return maxDistanceFromSpaceStation;
        }
}
