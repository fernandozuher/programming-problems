// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n1 = Reader.read(Integer::parseInt);
    int n2 = Reader.read(Integer::parseInt);
    IO.println(solveMeFirst(n1, n2));
}

// T: O(1)
// S: O(1) extra space
int solveMeFirst(int n1, int n2) {
    return n1 + n2;
}
