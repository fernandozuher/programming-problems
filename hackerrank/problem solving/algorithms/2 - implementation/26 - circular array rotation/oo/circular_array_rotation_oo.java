// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);
        final List<List<Integer>> INPUT = _readInput();
        final CircularArrayRotation OBJ = new CircularArrayRotation(INPUT);
        OBJ.printRotatedArrayElementsAccordingToQueries();
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
}

    class CircularArrayRotation {
        private List<Integer> _array;
        private int _arraySize;
        private int _rotationCount;
        private List<Integer> _queries;
        private int _querySize;

        public CircularArrayRotation(List<List<Integer>> input) {
            _array = input.get(0);
            _arraySize = input.get(1).get(0);
            _rotationCount = input.get(2).get(0);
            _queries = input.get(3);
            _querySize = input.get(4).get(0);

            _reduceInputRotations();
            _rotateInputArray();
        }

            private void _reduceInputRotations() {
                if (_arraySize > 1)
                    _rotationCount = _rotationCount >= _arraySize ? _rotationCount % _arraySize : _rotationCount;
                else
                    _rotationCount = 0;
            }

            private void _rotateInputArray() {
                final List<Integer> firstPartNewArray = _array.subList(_arraySize - _rotationCount, _arraySize);
                final List<Integer> secondPartNewArray = _array.subList(0, _arraySize - _rotationCount);

                final List<Integer> newArray = new ArrayList<Integer>(_arraySize);
                newArray.addAll(firstPartNewArray);
                newArray.addAll(secondPartNewArray);

                _array = newArray;
            }

        public void printRotatedArrayElementsAccordingToQueries() {
            _queries.forEach(query -> System.out.println(_array.get(query)));
        }
    }
