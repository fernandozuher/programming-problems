// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

void main() {
    IO.readln();
    IO.println(pickingNumbers(readNumbersIntoMap()));
}

Map<Integer, Integer> readNumbersIntoMap() {
    var arr = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    Map<Integer, Integer> counter = new HashMap<>();
    for (int num : arr)
        counter.put(num, counter.getOrDefault(num, 0) + 1);
    return counter;
}

int pickingNumbers(Map<Integer, Integer> counter) {
    int maxLen = 0;
    for (var num : counter.keySet()) {
        int current = counter.get(num) + counter.getOrDefault(num + 1, 0);
        maxLen = Math.max(maxLen, current);
    }
    return maxLen;
}
