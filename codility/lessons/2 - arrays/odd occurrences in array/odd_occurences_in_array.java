// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

import java.util.Arrays;

class Solution {

    public int solution(int[] A) {
        Arrays.sort(A);
        int unpairedElement = A[0];
        boolean isElementPaired = false;

        for (int i = 1, N = A.length; i < N; i++)
            if (A[i] == unpairedElement)
                isElementPaired = !isElementPaired;
            else if (isElementPaired) {
                isElementPaired = false;
                unpairedElement = A[i];
            }
            else
                break;

        return unpairedElement;
    }
}
