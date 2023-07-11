// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

import java.lang.Math;
import java.util.Arrays;

class Solution {
    public int solution(int[] array) {
        int firstPart = array[0];
        int secondPart = Arrays.stream(array).sum() - firstPart;
        int minimumDifferenceBetweenParts = Math.abs(firstPart - secondPart);

        for (int i = 1, size = array.length - 1; i < size; i++) {
            firstPart += array[i];
            secondPart -= array[i];
            final int currentMinimum = Math.abs(firstPart - secondPart);
            minimumDifferenceBetweenParts = Math.min(minimumDifferenceBetweenParts, currentMinimum);
        }

        return minimumDifferenceBetweenParts;
    }
}
