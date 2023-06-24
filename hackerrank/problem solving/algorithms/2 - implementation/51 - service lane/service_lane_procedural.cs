// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

using System;

public class ServiceLane {
    public static void Main() {
        List<int> inputLine = _readAnIntArray();
        int _ = inputLine.First();
        int nTestCases = inputLine.Last();
        List<int> widthMeasurements = _readAnIntArray();

        List<int> maximumAffordableWidthsVehicles = _findMaximumAffordableWidthsVehiclesWhileReadTestCases(nTestCases, widthMeasurements);
        maximumAffordableWidthsVehicles.ForEach(element => Console.WriteLine(element));
    }

        private static List<int> _readAnIntArray() {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static List<int> _findMaximumAffordableWidthsVehiclesWhileReadTestCases(int nTestCases, List<int> widthMeasurements) {
            return new List<int>(new int[nTestCases]).Select(_ => _maximumAffordableWidthVehicleInRange(widthMeasurements, _readAnIntArray())).ToList();
        }

            private static int _maximumAffordableWidthVehicleInRange(List<int> widthMeasurements, List<int> point) {
                int nElements = point.Last() - point.First() + 1;
                return (widthMeasurements.GetRange(point.First(), nElements)).Min();
            }
}
