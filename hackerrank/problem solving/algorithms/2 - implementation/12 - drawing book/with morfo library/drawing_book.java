// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    int page = Reader.read(Integer::parseInt);
    IO.println(pageCount(n, page));
}

// T: O(1)
// S: O(1) extra space
int pageCount(int n, int page) {
    int fromFront = page / 2;
    int fromBack = n / 2 - fromFront;
    return Math.min(fromFront, fromBack);
}
