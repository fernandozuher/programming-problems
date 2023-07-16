// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

import java.util.Arrays;

class Solution {
    public int[] solution(int nCounters, int[] array) {
        boolean foundMaxCounter = false;
        int max = 0;
        int[] counters = new int[nCounters + 1];

        for (int i = 0, currentMax = 0; i < array.length; i++)
            if (array[i] <= nCounters) {
                if (foundMaxCounter) {
                    // Arrays.fill(counters, 0), or changing the value to 0
                    // in a simple for-loop exceeds the time limit for a
                    // test case. Creating a new zero-default array succeeds in that.
                    counters = new int[nCounters + 1];
                    foundMaxCounter = false;
                    currentMax = 0;
                }
                if (++counters[array[i]] > currentMax)
                    currentMax++;
            }
            else if (!foundMaxCounter) {
                max += currentMax;
                foundMaxCounter = true;
            }

        if (foundMaxCounter)
            Arrays.fill(counters, max);
        else if (max > 0)
            for (int i = 1; i < counters.length; counters[i++] += max);

        return Arrays.copyOfRange(counters, 1, counters.length);
    }
}
