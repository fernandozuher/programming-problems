// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class FlatlandSpaceStations {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nCities = _scanner.nextInt(), nCitiesWithSpaceStation = _scanner.nextInt();
        final List<Integer> citiesWithSpaceStation = _readAnIntArray(nCitiesWithSpaceStation);
        System.out.println(_findMaximumDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        private static List<Integer> _readAnIntArray(int size) {
            return Arrays.asList(new Integer[size]).stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
        }

        private static int _findMaximumDistanceFromSpaceStation(int nCities, List<Integer> citiesWithSpaceStation) {
            int maxDistance = 0;

            Collections.sort(citiesWithSpaceStation);

            for (int cityI = 0; cityI < nCities; cityI++) {
                final int distance = _findMinDistanceBetweenCityAndNearestSpaceStation(cityI, citiesWithSpaceStation);
                maxDistance = Math.max(maxDistance, distance);
            }

            return maxDistance;
        }

            private static int _findMinDistanceBetweenCityAndNearestSpaceStation(int cityI, List<Integer> citiesWithSpaceStation) {
                final int element = _findElementOrNearest(cityI, citiesWithSpaceStation);
                final int minDistanceBetweenCityAndNearestSpaceStation = Math.abs(cityI - element);
                return minDistanceBetweenCityAndNearestSpaceStation;
            }

                private static int _findElementOrNearest(int n, List<Integer> array) {
                    int max = array.size() - 1;
                    int min = 0;

                    int minDistance = Integer.MAX_VALUE;
                    int nearestElement = ;

                    while (min <= max) {
                        final int mid = (int) Math.floor((min + max) / 2);

                        final int distance = Math.abs(array.get(mid) - n);
                        if (distance < minDistance) {
                            nearestElement = array.get(mid);
                            minDistance = distance;
                        }

                        if (array.get(mid) == n)
                            return n;
                        else if (array.get(mid) > n)
                            max = mid - 1;
                        else
                            min = mid + 1;
                    }

                    return nearestElement;
                }
}
