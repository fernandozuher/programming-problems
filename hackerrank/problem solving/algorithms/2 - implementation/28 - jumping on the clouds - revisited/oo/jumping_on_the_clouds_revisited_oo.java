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

        final JumpingOnTheClouds OBJ = new JumpingOnTheClouds(ARRAY, JUMP_LENGTH);
        System.out.println(OBJ.getRemainingEnergy());
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
}

    class JumpingOnTheClouds {
        private List<Integer> _array;
        private int _jumpLength;
        private int _energy;

        public JumpingOnTheClouds(List<Integer> array, int jumpLength) {
            _array = array;
            _jumpLength = jumpLength;
            _energy = 100;

            _jumpOnClouds();
        }

            private void _jumpOnClouds() {
                for (int cloudIndex = 0; true; ) {
                    _energy -= _spentEnergyAccordingToTypeOfCloud(_array.get(cloudIndex));
                    cloudIndex = _generateNewCloudIndex(cloudIndex);
                    if (_isCloudIndexBackToFirstCloud(cloudIndex))
                        break;
                }
            }

                private int _spentEnergyAccordingToTypeOfCloud(int cloudType) {
                    return cloudType == 0 ? 1 : 3;
                }

                private int _generateNewCloudIndex(int cloudIndex) {
                    return (cloudIndex + _jumpLength) % _array.size();
                }

                private boolean _isCloudIndexBackToFirstCloud(int cloudIndex) {
                    return cloudIndex == 0;
                }

        public int getRemainingEnergy() {
            return _energy;
        }
    }
