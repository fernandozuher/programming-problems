// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;


public class JumpingOnTheCloud {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_CLOUDS = _readANumber();
        final List<Integer> CLOUD_ARRAY = _readAnArray(N_CLOUDS);
        final int MINIMUM_NUMBER_OF_JUMPS = _calculateMinimumNumberOfJumps(CLOUD_ARRAY);

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

    private static int _calculateMinimumNumberOfJumps(List<Integer> array) {
        int jumps = 0;

        for (int i = 0, size = array.size() - 1; i < size; ) {
            i = _getIndexOfNextJump(i, array);
            jumps++;
        }

        return jumps;
    }

        private static int _getIndexOfNextJump(int index, List<Integer> array) {
            if (_isNextSecondIndexInsideRange(index + 2, array.size()))
                index += _isNextSecondCloudCumulus(array.get(index + 2)) ? 2 : 1;
            else
                index++;
            return index;
        }

            private static boolean _isNextSecondIndexInsideRange(int index, int size) {
                return index < size;
            }

            private static boolean _isNextSecondCloudCumulus(int typeOfCloud) {
                return typeOfCloud == 0;
            }
}
