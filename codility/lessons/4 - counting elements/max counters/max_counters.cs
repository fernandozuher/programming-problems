// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

using System;
using System.Linq;

class Solution {
    public int[] solution(int nCounters, int[] array) {
        bool foundMaxCounter = false;
        int max = 0;
        int[] counters = new int[nCounters + 1];
        int[] defaultArray = new int[nCounters + 1];

        for (int i = 0, currentMax = 0; i < array.Length; i++)
            if (array[i] <= nCounters) {
                if (foundMaxCounter) {
                    // Array.Fill(counters, 0), or creating another 0-default array,
                    // or changing the value to 0 in a simple for-loop
                    // exceeds the time limit for a test case. Array.Copy()
                    // from a zero-value array succeeds in that.
                    Array.Copy(defaultArray, counters, nCounters + 1);
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
            Array.Fill(counters, max);
        else if (max > 0)
            counters = counters.Select(element => element += max).ToArray();

        return new ArraySegment<int>(counters, 1, counters.Length - 1).ToArray();
    }
}
