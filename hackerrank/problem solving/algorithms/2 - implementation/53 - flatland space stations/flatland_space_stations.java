// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int nCities = _scanner.nextInt(), nCitiesWithSpaceStation = _scanner.nextInt();
        final List<Integer> citiesWithSpaceStation = _readAnIntArray(nCitiesWithSpaceStation);

        final FlatlandSpaceStations obj = new FlatlandSpaceStations(nCities, citiesWithSpaceStation);
        System.out.println(obj.getMaxDistanceFromSpaceStation());
    }

        private static List<Integer> _readAnIntArray(int size) {
            return Arrays.asList(new Integer[size]).stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
        }
}

    class FlatlandSpaceStations {
        int _nCities;
        List<Integer> _citiesWithSpaceStation;
        int _maxDistanceFromSpaceStation;

        public FlatlandSpaceStations(int nCities, List<Integer> citiesWithSpaceStation) {
            _nCities = nCities;
            _citiesWithSpaceStation = citiesWithSpaceStation;
            _maxDistanceFromSpaceStation = 0;

            Collections.sort(_citiesWithSpaceStation);
            _findMaxDistanceFromSpaceStation();
        }

            private void _findMaxDistanceFromSpaceStation() {
                final int firstCity = 0;
                _maxDistanceFromSpaceStation = _citiesWithSpaceStation.get(0) - firstCity;
                final int size = _citiesWithSpaceStation.size();

                for (int i = 1, previousCity = _citiesWithSpaceStation.get(0); i < size; i++) {
                    final int distance = _calculateDistanceBetweenCities(_citiesWithSpaceStation.get(i), previousCity);
                    _maxDistanceFromSpaceStation = Math.max(_maxDistanceFromSpaceStation, distance);
                    previousCity = _citiesWithSpaceStation.get(i);
                }

                if (!_hasLastCitySpaceStation()) {
                    final int distance = _calculateDistanceOfLastCity();
                    _maxDistanceFromSpaceStation = Math.max(_maxDistanceFromSpaceStation, distance);
                }
            }

                private int _calculateDistanceBetweenCities(int cityWithSpaceStation, int previousCity) {
                    return (cityWithSpaceStation - previousCity) / 2;
                }

                private boolean _hasLastCitySpaceStation() {
                    return _nCities-1 == _citiesWithSpaceStation.get(_citiesWithSpaceStation.size() - 1);
                }

                private int _calculateDistanceOfLastCity() {
                    return _nCities-1 - _citiesWithSpaceStation.get(_citiesWithSpaceStation.size() - 1);
                }

        public int getMaxDistanceFromSpaceStation() {
            return _maxDistanceFromSpaceStation;
        }
    }
