// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_CLOUDS = _readANumber();
        final List<Integer> CLOUD_ARRAY = _readAnArray(N_CLOUDS);

        final JumpingOnTheClouds OBJ = new JumpingOnTheClouds(CLOUD_ARRAY);
        final int MINIMUM_NUMBER_OF_JUMPS = OBJ.getMinimumNumberOfJumps();
        System.out.println(MINIMUM_NUMBER_OF_JUMPS);
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

    class JumpingOnTheClouds {
        private List<Integer> _cloudArray;
        private int _minimumNumberOfJumps;

        public JumpingOnTheClouds(List<Integer> cloudArray) {
            _cloudArray = cloudArray;
            _minimumNumberOfJumps = 0;

            _calculateMinimumNumberOfJumps();
        }

            private void _calculateMinimumNumberOfJumps() {
                for (int i = 0, size = _cloudArray.size() - 1; i < size; ) {
                    i = _getIndexOfNextJump(i);
                    _minimumNumberOfJumps++;
                }
            }

                private int _getIndexOfNextJump(int index) {
                    if (_isNextSecondIndexInsideRange(index + 2))
                        index += _isNextSecondCloudCumulus(_cloudArray.get(index + 2)) ? 2 : 1;
                    else
                        index++;
                    return index;
                }

                    private boolean _isNextSecondIndexInsideRange(int index) {
                        return index < _cloudArray.size();
                    }

                    private boolean _isNextSecondCloudCumulus(int typeOfCloud) {
                        return typeOfCloud == 0;
                    }

        public int getMinimumNumberOfJumps() {
            return _minimumNumberOfJumps;
        }
    }
