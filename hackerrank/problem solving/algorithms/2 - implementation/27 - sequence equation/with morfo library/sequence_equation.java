// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.io.Writer;

void main() {
    Reader.skipInputLn();
    int[] arr = Reader.readLnInts();
    Writer.println(sequenceEquation(arr));
}

// n: length of arr/output
// T: O(n)
// S: O(n) extra space
int[] sequenceEquation(int[] arr) {
    int[] valuesToIndex = new int[arr.length];
    int i = 0;
    for (int val : arr)
        valuesToIndex[val - 1] = i++;
    return Arrays.stream(valuesToIndex).map(val -> valuesToIndex[val] + 1).toArray();
}
