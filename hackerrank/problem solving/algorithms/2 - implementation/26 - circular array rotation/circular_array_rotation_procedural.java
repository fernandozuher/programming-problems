// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);
        List<List<Integer>> input = _readInput();

        input = _reduceInputRotations(input);
        input = _rotateInputArray(input);
        printRotatedArrayElementsAccordingToQueries(input);
    }

        private static List<List<Integer>> _readInput() {
            List<Integer> arraySize = _readANumberAndReturnItIntoList();
            List<Integer> rotationCount = _readANumberAndReturnItIntoList();
            List<Integer> queriesSize = _readANumberAndReturnItIntoList();

            List<Integer> array = _readArray(arraySize.get(0));
            List<Integer> queries = _readArray(queriesSize.get(0));

            List<List<Integer>> input = new ArrayList<List<Integer>>();
            input.add(array);
            input.add(arraySize);
            input.add(rotationCount);
            input.add(queries);
            input.add(queriesSize);

            return input;
        }

            private static List<Integer> _readANumberAndReturnItIntoList() {
                final int NUMBER = _scanner.nextInt();
                List<Integer> input = new ArrayList<Integer>();
                input.add(NUMBER);
                return input;
            }

            private static List<Integer> _readArray(int size) {
                List<Integer> array = Arrays.asList(new Integer[size]);
                for (int i = 0; i < size; i++)
                    array.set(i, _scanner.nextInt());
                return array;
            }

        private static List<List<Integer>> _reduceInputRotations(List<List<Integer>> input) {
            final int ARRAY_SIZE = input.get(0).size();
            int rotationCount = input.get(2).get(0);

            if (ARRAY_SIZE > 1)
                rotationCount = rotationCount >= ARRAY_SIZE ? rotationCount % ARRAY_SIZE : rotationCount;
            else
                rotationCount = 0;

            input.get(2).set(0, rotationCount);
            return input;
        }

        private static List<List<Integer>> _rotateInputArray(List<List<Integer>> input) {
            final List<Integer> ARRAY = input.get(0);
            final int ARRAY_SIZE = ARRAY.size();
            final int ROTATION_COUNT = input.get(2).get(0);

            final List<Integer> firstPartNewArray = ARRAY.subList(ARRAY_SIZE - ROTATION_COUNT, ARRAY_SIZE);
            final List<Integer> secondPartNewArray = ARRAY.subList(0, ARRAY_SIZE - ROTATION_COUNT);

            final List<Integer> newArray = new ArrayList<Integer>(ARRAY_SIZE);
            newArray.addAll(firstPartNewArray);
            newArray.addAll(secondPartNewArray);

            input.set(0, newArray);
            return input;
        }

        public static void printRotatedArrayElementsAccordingToQueries(List<List<Integer>> input) {
            final List<Integer> ARRAY = input.get(0);
            final List<Integer> QUERIES = input.get(3);
            QUERIES.forEach(query -> System.out.println(ARRAY.get(query)));
        }
}
