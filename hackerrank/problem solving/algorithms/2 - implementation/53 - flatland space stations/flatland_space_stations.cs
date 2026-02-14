// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

int nCities = ReadNumbers()[0];
int lastCity = nCities - 1;
int[] stations = ReadNumbers();
Array.Sort(stations);
Console.WriteLine(MaxDistanceFromSpaceStation(lastCity, stations));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

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
