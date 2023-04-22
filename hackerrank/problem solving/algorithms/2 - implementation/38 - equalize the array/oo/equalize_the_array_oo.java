// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int SIZE_ARRAY = _readANumber();
        final List<Integer> ARRAY = _readAnArray(SIZE_ARRAY);

        final EqualizeTheArray OBJ = new EqualizeTheArray(ARRAY);
        final int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED  = OBJ.getMinimumNumberOfDeletionsRequired();
        System.out.println(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);
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
}

    class EqualizeTheArray {
        private List<Integer> _array;
        private int _minimumNumberOfDeletionsRequired;

        public EqualizeTheArray(List<Integer> array) {
            Collections.sort(array);
            _array = array;
            _equalizeArray();
        }
        
            private void _equalizeArray() {
                final int MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = _findMaximumQuantityOfEqualElement();
                _minimumNumberOfDeletionsRequired = _array.size() - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
            }

                private int _findMaximumQuantityOfEqualElement() {
                    int maximumQuantityOfEqualElement = 1;

                    for (int i = 1, temporaryQuantityEqualElement = 1, size = _array.size(); i < size; i++) {
                        if (_areConsecutiveElementesEqual(_array.get(i - 1), _array.get(i))) {
                            temporaryQuantityEqualElement++;
                            maximumQuantityOfEqualElement = Math.max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
                        } else
                            temporaryQuantityEqualElement = 1;
                    }

                    return maximumQuantityOfEqualElement;
                }

                    private boolean _areConsecutiveElementesEqual(int element1, int element2) {
                        return element1 == element2;
                    }

        public int getMinimumNumberOfDeletionsRequired() {
            return _minimumNumberOfDeletionsRequired;
        }
    }
