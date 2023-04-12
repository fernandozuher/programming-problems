// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int SIZE = _readANumber();
        List<Integer> array = _readAnArray(SIZE);
        Collections.sort(array);

        final CutTheSticks OBJ = new CutTheSticks(array);
        final List<Integer> RESULT = OBJ.getRemainingSticksLengthArray();
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

        public static void printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}

    class CutTheSticks {
        private List<Integer> _sticksLengthArray;
        private int _sizeSticksLengthArray;
        private List<Integer> _remainingSticksLengthArray;

        public CutTheSticks(List<Integer> array) {
            _sticksLengthArray = array;
            _sizeSticksLengthArray = array.size();
            _initializeRemainingSticksLengthArray();
            _cutTheSticks();
        }

            private void _initializeRemainingSticksLengthArray() {
                _remainingSticksLengthArray = new ArrayList<Integer>() {{add(_sizeSticksLengthArray);}};
            }

            private void _cutTheSticks() {
                for (int i = 0; i < _sizeSticksLengthArray; ) {
                    final int SHORTEST_STICK_LENGTH = _sticksLengthArray.get(i);

                    i = _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i);
                    final int CURRENT_ITERATION_SIZE = _sizeSticksLengthArray - i;
                    if (i == _sizeSticksLengthArray)
                        break;

                    _remainingSticksLengthArray.add(CURRENT_ITERATION_SIZE);
                    _decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, SHORTEST_STICK_LENGTH);
                }
            }

                private int _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index) {
                    final int SHORTEST_STICK_LENGTH = _sticksLengthArray.get(index);
                    while (index < _sizeSticksLengthArray && _sticksLengthArray.get(index) == SHORTEST_STICK_LENGTH)
                        index++;
                    return index;
                }

                private void _decreaseSticksLengthsHigherThanCurrentShortestStickLength(int index, int shortestStickLength) {
                    _sticksLengthArray = _sticksLengthArray.stream().map(element -> element - shortestStickLength).collect(Collectors.toList());
                }

        public List<Integer> getRemainingSticksLengthArray() {
            return _remainingSticksLengthArray;
        }
    }
