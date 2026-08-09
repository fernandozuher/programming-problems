// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// Java 25

import morfo.collections.Counter;
import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    int[] arr = Reader.readLnInts();
    var freqMap = counter(arr);
    IO.println(pickingNumbers(freqMap));
}

Map<Integer, Integer> counter(int[] arr) {
    return Counter.of(Arrays.stream(arr).boxed().toList());
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int pickingNumbers(Map<Integer, Integer> freqMap) {
    int maxLen = 0;
    for (var num : freqMap.keySet()) {
        int current = freqMap.get(num) + freqMap.getOrDefault(num + 1, 0);
        maxLen = Math.max(maxLen, current);
    }
    return maxLen;
}
