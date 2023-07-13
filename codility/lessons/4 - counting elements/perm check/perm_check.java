// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

import java.util.Arrays;

class Solution {
    public int solution(int[] array) {
        Arrays.sort(array);
        int i;
        for (i = 0; i < array.length && array[i] == i + 1; ++i);
        return i == array.length ? 1 : 0;
    }
}
