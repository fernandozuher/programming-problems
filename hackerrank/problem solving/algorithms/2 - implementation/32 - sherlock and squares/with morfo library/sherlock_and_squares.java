// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++) {
        int a = Reader.read(Integer::parseInt);
        int b = Reader.read(Integer::parseInt);
        IO.println(squares(a, b));
    }
}

// T: O(1)
// S: O(1) extra space
int squares(int startNum, int endNum) {
    int maxSquare = (int) Math.floor(Math.sqrt(endNum));
    int minSquare = (int) Math.ceil(Math.sqrt(startNum));
    return maxSquare - minSquare + 1;
}
