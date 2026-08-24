// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.math.Sum;

void main() {
    Reader.skipInputLn();
    IO.println(sumStdin());
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
int sumStdin() {
    return Sum.ofInts(Reader.readLnInts());
}
