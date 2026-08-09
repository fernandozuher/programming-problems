// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int t = Reader.readLnInts()[1];
    int[] widths = Reader.readLnInts();
    for (int i = 0; i < t; i++)
        IO.println(minWidthInSegment(widths, Reader.readLnInts()));
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment) {
    int start = segment[0], finish = segment[1];
    return Arrays.stream(widths, start, finish + 1).min().getAsInt();
}
