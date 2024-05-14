// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// From Java 21

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int nCities = scan.nextInt();
        int nCitiesWithSpaceStation = scan.nextInt();
        List<Integer> citiesWithSpaceStation = readIntArray(nCitiesWithSpaceStation);
        Collections.sort(citiesWithSpaceStation);
        System.out.println(findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        public static List<Integer> readIntArray(int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static int findMaxDistanceFromSpaceStation(final int nCities, final List<Integer> citiesWithSpaceStation) {
            final int[] maxDistanceFromSpaceStation = new int[1];
            final int[] previousCity = new int[1];
            maxDistanceFromSpaceStation[0] = previousCity[0] = citiesWithSpaceStation.getFirst();

            citiesWithSpaceStation.stream().skip(1).forEach(cityWithSpaceStation -> {
                int distanceBetweenCities = (cityWithSpaceStation - previousCity[0]) / 2;
                maxDistanceFromSpaceStation[0] = Math.max(maxDistanceFromSpaceStation[0], distanceBetweenCities);
                previousCity[0] = cityWithSpaceStation;
            });

            boolean hasLastCitySpaceStation = nCities - 1 == citiesWithSpaceStation.getLast();
            if (!hasLastCitySpaceStation) {
                int distanceOfLastCity = nCities - 1 - citiesWithSpaceStation.getLast();
                maxDistanceFromSpaceStation[0] = Math.max(maxDistanceFromSpaceStation[0], distanceOfLastCity);
            }

            return maxDistanceFromSpaceStation[0];
        }
}
