// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

record State(int x1, int v1, int x2, int v2) {
}

void main() {
    State initialState = readInput();
    IO.println(kangaroo(initialState) ? "YES" : "NO");
}

State readInput() {
    var arr = Reader.read(4, Integer::parseInt);
    return new State(arr.get(0), arr.get(1), arr.get(2), arr.get(3));
}

// T: O(1)
// S: O(1) extra space
boolean kangaroo(State s) {
    if (s.v1 == s.v2) return s.x1 == s.x2;
    int distanceDiff = s.x2 - s.x1;
    int velocityDiff = s.v1 - s.v2;
    return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff == 0;
}
