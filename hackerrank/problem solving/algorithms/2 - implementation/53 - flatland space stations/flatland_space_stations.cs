// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int nCities = ReadNumbers()[0];
        int[] stations = ReadNumbers();
        Array.Sort(stations);
        Console.WriteLine(MaxDistanceFromSpaceStation(nCities, stations));
    }

    private static int[] ReadNumbers()
    {
        return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
    }

    private static int MaxDistanceFromSpaceStation(int nCities, int[] stations)
    {
        int maxDist = stations[0];

        for (int i = 1; i < stations.Length; i++)
        {
            int gap = (stations[i] - stations[i-1]) / 2;
            maxDist = Math.Max(maxDist, gap);
        }

        int lastCity = nCities - 1;
        return Math.Max(maxDist, lastCity - stations[^1]);
    }
}
