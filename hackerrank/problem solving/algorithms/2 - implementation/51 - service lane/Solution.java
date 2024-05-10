// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int nWidthMeasurements = scan.nextInt();
        int n = scan.nextInt();
        findMaximumAffordableWidthsVehiclesWhileReadTestCases(n, readIntArray(nWidthMeasurements)).forEach(System.out::println);
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static List<Integer> findMaximumAffordableWidthsVehiclesWhileReadTestCases(final int n, final List<Integer> widthMeasurements) {
            final int testCaseSize = 2;
            return Arrays.stream(new Integer[n])
                   .map(_ -> maximumAffordableWidthVehicleInRange(widthMeasurements, readIntArray(testCaseSize)))
                   .collect(toList());
        }

            public static int maximumAffordableWidthVehicleInRange(final List<Integer> widthMeasurements, final List<Integer> point) {
                return Collections.min(widthMeasurements.subList(point.get(0), point.get(1) + 1));
            }
}
