// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

import java.util.Arrays;

class Solution {

    public int[] solution(int[] A, int K) {
        final int[] rotatedArray = isThereRotation(A, K);

        if (rotatedArray != null)
            return rotatedArray;
        else
            return A;
    }

        private static int[] isThereRotation(int[] array, int rotation) {
            final int newRotation = reduceRotations(array.length, rotation);

            if (newRotation > 0) {
                final int[] rotatedArray = rotateElements(array, newRotation);
                return rotatedArray;
            } else
                return null;
        }

            private static int reduceRotations(int arraySize, int rotation) {
                if (arraySize > 1)
                    return rotation >= arraySize ? rotation % arraySize : rotation;
                else
                    return 0;
            }

            private static int[] rotateElements(int[] array, int rotation) {
            final int N = array.length;

            int newArray[] = Arrays.copyOf(Arrays.copyOfRange(array, N - rotation, N), N);
            System.arraycopy(Arrays.copyOfRange(array, 0, N - rotation), 0, newArray, rotation, N - rotation);

            return newArray;
        }
}
