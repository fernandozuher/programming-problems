// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Solution {
    private static Scanner _scanner;

    public static void main(String args[]) {
        _scanner = new Scanner(System.in);

        final int SIZE = _readANumber();
        final List<Integer> ARRAY = _readAnArray(SIZE);

        final Sequence_Equation OBJ = new Sequence_Equation(ARRAY);
        OBJ.printPermutatedArray();
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
}

    class Sequence_Equation {
        private List<Integer> _inputArray;
        private List<Integer> _elementsPositionsArray;
        private List<Integer> _permutatedArray;

        public Sequence_Equation(List<Integer> array) {
            _inputArray = new ArrayList<Integer>(array);
            _elementsPositionsArray = _generateElementsPositionsArray();
            _permutatedArray = _generatePermutatedArray();
        }

            private List<Integer> _generateElementsPositionsArray() {
                List<Integer> elementsPositionsArray = Arrays.asList(new Integer[_inputArray.size()]);
                for (int i = 0, size = _inputArray.size(); i < size; i++) {
                    final int NEW_POSITION = _inputArray.get(i) - 1;
                    elementsPositionsArray.set(NEW_POSITION, i);
                }
                return elementsPositionsArray;
            }

            private List<Integer> _generatePermutatedArray() {
                List<Integer> permutatedArray = Arrays.asList(new Integer[_elementsPositionsArray.size()]);
                for (int i = 0, size = _elementsPositionsArray.size(); i < size; i++) {
                    final int ELEMENT = _elementsPositionsArray.get(_elementsPositionsArray.get(i)) + 1;
                    permutatedArray.set(i, ELEMENT);
                }
                return permutatedArray;
            }

        public void printPermutatedArray() {
            _permutatedArray.forEach(System.out::println);
        }
    }
