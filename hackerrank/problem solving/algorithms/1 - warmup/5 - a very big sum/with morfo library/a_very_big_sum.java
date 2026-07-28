// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    long[] arr = Reader.readLnLongs();
    IO.println(aVeryBigSum(arr));
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long aVeryBigSum(long[] arr) {
    return Arrays.stream(arr).sum();
}
