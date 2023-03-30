// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;


public class Solution {
    private static Scanner _scanner;

    public static void main(String args[]) {
        _scanner = new Scanner(System.in);

        final int SIZE_ARRAY = _readANumber();
        final int JUMP_LENGTH = _readANumber();
        final List<Integer> ARRAY = _readAnArray(SIZE_ARRAY);

        final int ENERGY = _jumpingOnClouds(ARRAY, JUMP_LENGTH);
        System.out.println(ENERGY);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static List<Integer> _readAnArray(int sizeArray) {
            List<Integer> array = Arrays.asList(new Integer[sizeArray]);
            for (int i = 0; i < sizeArray; i++)
                array.set(i, _scanner.nextInt());
            return array;
        }

        private static int _jumpingOnClouds(List<Integer> array, int jumpLength) {
            int energy = 100;

            for (int cloudIndex = 0; true; ) {
                energy -= _spentEnergyAccordingToTypeOfCloud(array.get(cloudIndex));
                cloudIndex = _generateNewCloudIndex(cloudIndex, array.size(), jumpLength);
                if (_isCloudIndexBackToFirstCloud(cloudIndex))
                    break;
            }

            return energy;
        }

            private static int _spentEnergyAccordingToTypeOfCloud(int cloudType) {
                return cloudType == 0 ? 1 : 3;
            }

            private static int _generateNewCloudIndex(int cloudIndex, int sizeArray, int jumpLength) {
                return (cloudIndex + jumpLength) % sizeArray;
            }

            private static boolean _isCloudIndexBackToFirstCloud(int cloudIndex) {
                return cloudIndex == 0;
            }
}
