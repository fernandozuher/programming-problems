// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    Reader.skipInput();
    int maxJump = Reader.read(Integer::parseInt);
    int[] hurdles = Reader.readLnInts();
    IO.println(hurdleRace(hurdles, maxJump));
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int hurdleRace(int[] hurdles, int maxJump) {
    return Math.max(0, Arrays.stream(hurdles).max().getAsInt() - maxJump);
}
