// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int[] solution(int nCounters, int[] array) {
        boolean foundMaxCounter = false;
        int max = 0, currentMax = 0;
        var counters = new HashMap<Integer, Integer>();

        for (int element : array)
            if (element <= nCounters) {
                if (foundMaxCounter) {
                    counters.clear();
                    foundMaxCounter = false;
                    currentMax = 0;
                }

                incrementCounter(element, counters);
                if (counters.get(element) > currentMax)
                    currentMax++;

            } else if (!foundMaxCounter) {
                max += currentMax;
                foundMaxCounter = true;
            }

        return compouseResult(foundMaxCounter, max, nCounters, counters);
    }

        private static void incrementCounter(int counter, Map<Integer, Integer> counters) {
            int value = counters.getOrDefault(counter, 0);
            counters.put(counter, ++value);
        }

        private static int[] compouseResult(boolean foundMaxCounter, int max, int nCounters, Map<Integer, Integer> counters) {
            final int initialValue = foundMaxCounter || max > 0 ? max : 0;
            int[] result = new int[nCounters + 1];
            Arrays.fill(result, initialValue);

            if (!foundMaxCounter)
                for (var element : counters.entrySet())
                    result[element.getKey()] += element.getValue();

            return Arrays.copyOfRange(result, 1, result.length);
        }
}
