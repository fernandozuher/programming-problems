// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

using Morfo.IO;

int nCities = Reader.ReadLn<int, int[]>()[0];
int lastCity = nCities - 1;
int[] stations = Reader.ReadLn<int, int[]>();
Array.Sort(stations);
Console.WriteLine(MaxDistanceFromSpaceStation(lastCity, stations));

// n: length of stations
// T: O(n)
// S: O(1) extra space
int MaxDistanceFromSpaceStation(int lastCity, int[] stations)
{
    int maxDist = stations[0];

    foreach (var (prev, curr) in stations.Zip(stations.Skip(1)))
    {
        int gap = (curr - prev) / 2;
        maxDist = Math.Max(maxDist, gap);
    }

    return Math.Max(maxDist, lastCity - stations[^1]);
}
