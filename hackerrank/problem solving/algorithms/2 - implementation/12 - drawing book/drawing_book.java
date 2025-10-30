// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true
// Java 25

import java.lang.IO;

void main() {
    int n = Integer.parseInt(IO.readln());
    int page = Integer.parseInt(IO.readln());
    IO.println(pageCount(n, page));
}

int pageCount(int n, int page) {
    int fromFront = page / 2;
    int fromBack = n / 2 - fromFront;
    return Math.min(fromFront, fromBack);
}
