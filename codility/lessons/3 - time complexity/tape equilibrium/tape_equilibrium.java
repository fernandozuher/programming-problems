// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

import java.lang.Math;
import java.util.Arrays;

class Solution {

    public int solution(int[] array) {
        final int MINIMUM_DIFFERENCE_BETWEEN_PARTS = findMinimumDifferenceBetweenTwoPartsArray(array);
        return MINIMUM_DIFFERENCE_BETWEEN_PARTS;
    }

        private static int findMinimumDifferenceBetweenTwoPartsArray(int[] array) {
            int firstPart = array[0];
            int secondPart = sumArrayElements(array) - firstPart;
            int minimumDifferenceBetweenParts = Math.abs(firstPart - secondPart);

            for (int i = 1, size = array.length - 1; i < size; i++) {
                firstPart += array[i];
                secondPart -= array[i];
                final int CURRENT_MINIMUM = Math.abs(firstPart - secondPart);

                if (minimumDifferenceBetweenParts > CURRENT_MINIMUM)
                    minimumDifferenceBetweenParts = CURRENT_MINIMUM;
            }

            return minimumDifferenceBetweenParts;
        }

            private static int sumArrayElements(int[] array) {
                return Arrays.stream(array).sum();
            }
}
