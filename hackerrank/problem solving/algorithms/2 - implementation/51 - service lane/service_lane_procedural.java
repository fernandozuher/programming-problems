// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class ServiceLane {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nWidthMeasurements = _scanner.nextInt();
        final int nTestCases = _scanner.nextInt();
        final List<Integer> widthMeasurements = readAnIntArray(nWidthMeasurements);

        final List<Integer> maximumAffordableWidthsVehicles = findMaximumWidthsVehiclesWhileReadTestCases(nTestCases, widthMeasurements);
        maximumAffordableWidthsVehicles.forEach(System.out::println);
    }

        private static List<Integer> readAnIntArray(int size) {
            return Arrays.asList(new Integer[size]).stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
        }

        private static List<Integer> findMaximumWidthsVehiclesWhileReadTestCases(int nTestCases, List<Integer> widthMeasurements) {
            List<Integer> maximumAffordableWidthsVehicles = Arrays.asList(new Integer[nTestCases]);

            for (int i = 0; i < nTestCases; i++) {
                int[] point = {_scanner.nextInt(), _scanner.nextInt()};
                maximumAffordableWidthsVehicles.set(i, maximumAffordableWidthVehicleInRange(widthMeasurements, point));
            }

            return maximumAffordableWidthsVehicles;
        }

            private static int maximumAffordableWidthVehicleInRange(List<Integer> widthMeasurements, int[] point) {
                return Collections.min(widthMeasurements.subList(point[0], point[1] + 1));
            }
}
