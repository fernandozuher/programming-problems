// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

using System;
using System.Collections.Generic;
using System.Linq;

class Solution {
    public int[] solution(int nCounters, int[] array)
    {
        bool foundMaxCounter = false;
        int max = 0, currentMax = 0;
        var counters = new Dictionary<int, int>();

        foreach (int element in array)
            if (element <= nCounters) {
                if (foundMaxCounter)
                    _setDefaultZeroValues(ref counters, ref foundMaxCounter, ref currentMax);

                _incrementCounter(element, counters);
                if (counters[element] > currentMax)
                    currentMax++;

            } else if (!foundMaxCounter) {
                max += currentMax;
                foundMaxCounter = true;
            }

        return _compouseResult(foundMaxCounter, max, nCounters, counters);
    }

        private static void _setDefaultZeroValues(ref Dictionary<int, int> counters, ref bool foundMaxCounter, ref int currentMax)
        {
            counters.Clear();
            foundMaxCounter = false;
            currentMax = 0;
        }

        private static void _incrementCounter(int counter, Dictionary<int, int> counters)
        {
            counters.TryGetValue(counter, out int value);
            counters[counter] = ++value;
        }

        private static int[] _compouseResult(bool foundMaxCounter, int max, int nCounters, Dictionary<int, int> counters)
        {
            int initialValue = foundMaxCounter || max > 0 ? max : 0;
            int[] result = Enumerable.Repeat(initialValue, nCounters + 1).ToArray();

            if (!foundMaxCounter)
                foreach (var element in counters)
                    result[element.Key] += element.Value;

            return new ArraySegment<int>(result, 1, result.Length - 1).ToArray();
        }
}
