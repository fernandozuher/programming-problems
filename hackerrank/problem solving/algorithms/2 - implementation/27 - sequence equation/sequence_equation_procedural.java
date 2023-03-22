// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class Solution {
    private static Scanner _scanner;

    public static void main(String args[]) {
        _scanner = new Scanner(System.in);

        final int SIZE = _readANumber();
        final List<Integer> ARRAY = _readAnArray(SIZE);

        final List<Integer> PERMUTATED_ARRAY = _permutationEquation(ARRAY);
        printArray(PERMUTATED_ARRAY);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static List<Integer> _readAnArray(int size) {
            List<Integer> array = Arrays.asList(new Integer[size]);
            for (int i = 0; i < size; i++)
                array.set(i, _scanner.nextInt());
            return array;
        }

        private static List<Integer> _permutationEquation(List<Integer> array) {
            final List<Integer> ARRAY_ELEMENTS_POSITIONS = _generateArrayOfElementsPositions(array);
            final List<Integer> PERMUTATED_ARRAY = _generatePermutatedArray(ARRAY_ELEMENTS_POSITIONS);
            return PERMUTATED_ARRAY;
        }

            private static List<Integer> _generateArrayOfElementsPositions(List<Integer> array) {
                List<Integer> arrayElementsPositions = Arrays.asList(new Integer[array.size()]);
                for (int i = 0, size = array.size(); i < size; i++) {
                    final int NEW_POSITION = array.get(i) - 1;
                    arrayElementsPositions.set(NEW_POSITION, i);
                }
                return arrayElementsPositions;
            }

            private static List<Integer> _generatePermutatedArray(List<Integer> array) {
                List<Integer> permutatedArray = Arrays.asList(new Integer[array.size()]);
                for (int i = 0, size = array.size(); i < size; i++) {
                    final int ELEMENT = array.get(array.get(i)) + 1;
                    permutatedArray.set(i, ELEMENT);
                }
                return permutatedArray;
            }

        public static void printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
