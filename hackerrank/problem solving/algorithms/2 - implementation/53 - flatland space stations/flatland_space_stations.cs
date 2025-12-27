// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

int nCities = ReadNumbers()[0];
int lastCity = nCities - 1;
int[] stations = ReadNumbers();
Array.Sort(stations);
Console.WriteLine(MaxDistanceFromSpaceStation(lastCity, stations));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int MaxDistanceFromSpaceStation(int lastCity, int[] stations)
{
    int maxDist = stations[0];

    for (int i = 1; i < stations.Length; i++)
    {
        int gap = (stations[i] - stations[i-1]) / 2;
        maxDist = Math.Max(maxDist, gap);
    }

    return Math.Max(maxDist, lastCity - stations[^1]);
}
