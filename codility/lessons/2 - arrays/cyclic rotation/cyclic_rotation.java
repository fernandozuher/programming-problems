// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

import java.util.Arrays;


class Solution {

    public int[] solution(int[] A, int K) {
        final int[] ROTATED_ARRAY = isThereRotation(A, K);

        if (ROTATED_ARRAY != null)
            return ROTATED_ARRAY;
        else
            return A;
    }

        public int[] isThereRotation(int[] array, int rotation) {
            final int NEW_ROTATION = reduceRotations(array.length, rotation);

            if (NEW_ROTATION > 0) {
                final int[] ROTATED_ARRAY = rotateElements(array, NEW_ROTATION);
                return ROTATED_ARRAY;
            }
            else
                return null;
        }

            public int reduceRotations(int array_size, int rotation) {
                if (array_size > 1)
                    return rotation >= array_size ? rotation % array_size : rotation;
                else
                    return 0;
            }

            public int[] rotateElements(int[] array, int rotation) {
                final int N = array.length;

                int new_array[] = Arrays.copyOf(Arrays.copyOfRange(array, N - rotation, N), N);
                System.arraycopy(Arrays.copyOfRange(array, 0, N - rotation), 0, new_array, rotation, N - rotation);

                return new_array;
            }
}
