// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;
import java.lang.Math;

public class FlatlandSpaceStations {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nCities = _scanner.nextInt(), nCitiesWithSpaceStation = _scanner.nextInt();
        final List<Integer> citiesWithSpaceStation = _readAnIntArray(nCitiesWithSpaceStation);
        System.out.println(_findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
    }

        private static List<Integer> _readAnIntArray(int size) {
            return Arrays.asList(new Integer[size]).stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
        }

        private static int _findMaxDistanceFromSpaceStation(int nCities, List<Integer> citiesWithSpaceStation) {
            Collections.sort(citiesWithSpaceStation);
            final int firstCity = 0;
            int maxDistance = citiesWithSpaceStation.get(0) - firstCity;
            final int size = citiesWithSpaceStation.size();

            for (int i = 1, previousCity = citiesWithSpaceStation.get(0); i < size; i++) {
                final int distance = _calculateDistanceBetweenCities(citiesWithSpaceStation.get(i), previousCity);
                maxDistance = Math.max(maxDistance, distance);
                previousCity = citiesWithSpaceStation.get(i);
            }

            final int lastCity = nCities - 1;
            final int lastCityWithSpaceStation = citiesWithSpaceStation.get(size - 1);
            if (!_hasLastCitySpaceStation(lastCity, lastCityWithSpaceStation)) {
                final int distance = _calculateDistanceOfLastCity(lastCity, lastCityWithSpaceStation);
                maxDistance = Math.max(maxDistance, distance);
            }

            return maxDistance;
        }

            private static int _calculateDistanceBetweenCities(int cityWithSpaceStation, int previousCity) {
                return (cityWithSpaceStation - previousCity) / 2;
            }

            private static boolean _hasLastCitySpaceStation(int lastCity, int lastCityWithSpaceStation) {
                return lastCity == lastCityWithSpaceStation;
            }

            private static int _calculateDistanceOfLastCity(int lastCity, int lastCityWithSpaceStation) {
                return lastCity - lastCityWithSpaceStation;
            }
}
