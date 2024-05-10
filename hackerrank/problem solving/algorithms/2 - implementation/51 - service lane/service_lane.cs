// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> inputLine = ReadIntArray();
        int _ = inputLine.First();
        int n = inputLine.Last();
        FindMaximumAffordableWidthsVehiclesWhileReadTestCases(n, ReadIntArray()).ForEach(WriteLine);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static List<int> FindMaximumAffordableWidthsVehiclesWhileReadTestCases(int n, List<int> widthMeasurements)
        {
            return new List<int>(new int[n]).Select(_ => MaximumAffordableWidthVehicleInRange(widthMeasurements, ReadIntArray())).ToList();
        }

            static int MaximumAffordableWidthVehicleInRange(List<int> widthMeasurements, List<int> point)
            {
                int nElements = point.Last() - point.First() + 1;
                return (widthMeasurements.GetRange(point.First(), nElements)).Min();
            }
}
