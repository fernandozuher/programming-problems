// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// Java 25

record State(int x1, int v1, int x2, int v2) {
}

void main() {
    State initialState = readInput();
    IO.println(kangaroo(initialState) ? "YES" : "NO");
}

State readInput() {
    var arr = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    return new State(arr[0], arr[1], arr[2], arr[3]);
}

// T: O(1)
// S: O(1) extra space
boolean kangaroo(State s) {
    if (s.v1 == s.v2) return s.x1 == s.x2;
    int distanceDiff = s.x2 - s.x1;
    int velocityDiff = s.v1 - s.v2;
    return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff == 0;
}
