// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

public class CutTheSticks {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int SIZE = _readANumber();
        List<Integer> array = _readAnArray(SIZE);
        Collections.sort(array);

        final List<Integer> RESULT = _cutTheSticks(array);
        printArray(RESULT);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static List<Integer> _readAnArray(int size) {
            List<Integer> array = Arrays.asList(new Integer[size]);
            array = array.stream().map(element -> _scanner.nextInt()).collect(Collectors.toList());
            return array;
        }

        private static List<Integer> _cutTheSticks(List<Integer> array) {
            final int SIZE = array.size();
            List<Integer> remainingSticksOfEachIteration = _initializeResult(SIZE);

            for (int i = 0; i < SIZE; ) {
                final int SHORTEST_STICK_LENGTH = array.get(i);

                i = _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array);
                final int CURRENT_ITERATION_SIZE = SIZE - i;
                if (i == SIZE)
                    break;

                remainingSticksOfEachIteration.add(CURRENT_ITERATION_SIZE);
                _decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, SHORTEST_STICK_LENGTH);
            }

            return remainingSticksOfEachIteration;
        }

            private static List<Integer> _initializeResult(int size) {
                List<Integer> remainingSticksOfEachIteration = new ArrayList<Integer>();
                remainingSticksOfEachIteration.add(size);
                return remainingSticksOfEachIteration;
            }

            private static int _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index, List<Integer> array) {
                final int SIZE = array.size();
                final int SHORTEST_STICK_LENGTH = array.get(index);
                while (index < SIZE && array.get(index) == SHORTEST_STICK_LENGTH)
                    index++;
                return index;
            }

            private static void _decreaseSticksLengthsHigherThanCurrentShortestStickLength(int index, List<Integer> array, int shortestStickLength) {
                array = array.stream().map(element -> element - shortestStickLength).collect(Collectors.toList());
            }

        public static void printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
