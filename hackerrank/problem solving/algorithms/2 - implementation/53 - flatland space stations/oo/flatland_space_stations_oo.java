// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

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
                for (int cityI = 0; cityI < _nCities; cityI++) {
                    final int distance = _findMinDistanceBetweenCityAndNearestSpaceStation(cityI);
                    _maxDistanceFromSpaceStation = Math.max(_maxDistanceFromSpaceStation, distance);
                }
            }

                private int _findMinDistanceBetweenCityAndNearestSpaceStation(int cityI) {
                    final int element = _findElementOrNearest(cityI, _citiesWithSpaceStation);
                    final int minDistanceBetweenCityAndNearestSpaceStation = Math.abs(cityI - element);
                    return minDistanceBetweenCityAndNearestSpaceStation;
                }

                    private int _findElementOrNearest(int n, List<Integer> array) {
                        int max = array.size() - 1;
                        int min = 0;

                        int minDistance = Integer.MAX_VALUE;
                        int nearestElement = n;

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

        public int getMaxDistanceFromSpaceStation() {
            return _maxDistanceFromSpaceStation;
        }
    }
