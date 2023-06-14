// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int size = _readANumber();
        final int beautifulDifference = _readANumber();
        final List<Integer> array = _readAnArray(size);

        final BeautifulTriplets obj = new BeautifulTriplets(array, beautifulDifference);
        System.out.println(obj.getNBeautifulTriplets());
    }

        private static int _readANumber() {
            final int number = _scanner.nextInt();
            return number;
        }

        private static List<Integer> _readAnArray(int size) {
            List<Integer> array = Arrays.asList(new Integer[size]);
            array = array.stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
            return array;
        }
}

    class BeautifulTriplets {
        private List<Integer> _array;
        private int _beautifulDifference;
        private int _nBeautifulTriplets;

        public BeautifulTriplets(List<Integer> array, int beautifulDifference) {
            _array = array;
            _beautifulDifference = beautifulDifference;
            _findBeautifulTriplets();
        }

            private void _findBeautifulTriplets() {
                _nBeautifulTriplets = 0;

                if (_array.size() > 2)
                    for (int i = 0; i < _array.size() - 2; i++)
                        for (int j = i + 1; j < _array.size() - 1; j++) {
                            final int firstDifference = _array.get(j) - _array.get(i);

                            if (firstDifference < _beautifulDifference)
                                continue;
                            else if (firstDifference > _beautifulDifference)
                                break;

                            for (int k = j + 1; k < _array.size(); k++) {
                                final int secondDifference = _array.get(k) - _array.get(j);

                                if (secondDifference == _beautifulDifference)
                                    _nBeautifulTriplets++;
                                else if (secondDifference > _beautifulDifference)
                                    break;
                            }
                        }
            }

        public int getNBeautifulTriplets() {
            return _nBeautifulTriplets;
        }
    }
