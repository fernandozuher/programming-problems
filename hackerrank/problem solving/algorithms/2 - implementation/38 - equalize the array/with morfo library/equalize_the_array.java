// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// Java 25

import morfo.collections.Counter;
import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    int[] arr = Reader.readLnInts();
    IO.println(minDeletionsToEqualize(arr));
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
int minDeletionsToEqualize(int[] arr) {
    return arr.length - Collections.max(counter(arr).values());
}

Map<Integer, Integer> counter(int[] arr) {
    return Counter.of(Arrays.stream(arr).boxed().toList());
}
