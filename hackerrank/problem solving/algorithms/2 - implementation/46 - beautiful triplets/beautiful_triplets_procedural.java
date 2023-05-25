// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class BeautifulTriplets {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int size = _readANumber();
        final int beautifulDifference = _readANumber();
        final List<Integer> array = _readAnArray(size);

        final int nBeautifulTriplets = _findBeautifulTriplets(array, beautifulDifference);
        System.out.println(nBeautifulTriplets);
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

        private static int _findBeautifulTriplets(List<Integer> array, int beautifulDifference) {
            int nBeautifulTriplets = 0;

            if (array.size() > 2)
                for (int i = 0; i < array.size() - 2; i++)
                    for (int j = i + 1; j < array.size() - 1; j++) {
                        final int firstDifference = array.get(j) - array.get(i);

                        if (firstDifference < beautifulDifference)
                            continue;
                        else if (firstDifference > beautifulDifference)
                            break;

                        for (int k = j + 1; k < array.size(); k++) {
                            final int secondDifference = array.get(k) - array.get(j);

                            if (secondDifference == beautifulDifference)
                                nBeautifulTriplets++;
                            else if (secondDifference > beautifulDifference)
                                break;
                        }
                    }

            return nBeautifulTriplets;
        }
}
