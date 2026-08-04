// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    IO.println(diagonalDifference(n));
}

// T: O(n^2)
// S: O(n) extra space
int diagonalDifference(int n) {
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        int[] arr = Reader.readLnInts();
        primarySum += arr[i];
        secondarySum += arr[n - i - 1];
    }

    return Math.abs(primarySum - secondarySum);
}
