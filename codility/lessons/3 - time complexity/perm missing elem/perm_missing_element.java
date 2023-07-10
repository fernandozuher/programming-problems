// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

import java.util.Arrays;

class Solution {
    public int solution(int[] array) {
        Arrays.sort(array);
        return findMissingElement(array);
    }

        private static int findMissingElement(int[] array) {
            int i;
            for (i = 0; i < array.length; i++)
                if (array[i] != i + 1)
                    break;
            return i + 1;
        }
}
