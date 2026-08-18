// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// Java 25

import morfo.collections.Counter;
import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    var socksToCounts = counter(Reader.readLnInts());
    IO.println(sockMerchant(socksToCounts));
}

Map<Integer, Integer> counter(int[] arr) {
    return Counter.of(Arrays.stream(arr).boxed().toList());
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
int sockMerchant(Map<Integer, Integer> socksToCounts) {
    return socksToCounts.values().stream().mapToInt(x -> x / 2).sum();
}
