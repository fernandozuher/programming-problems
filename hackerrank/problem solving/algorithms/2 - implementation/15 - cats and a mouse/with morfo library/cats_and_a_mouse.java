// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++)
        IO.println(findNearestCatOrNot(Reader.readLnInts()));
}

// T: O(1)
// S: O(1) extra space
String findNearestCatOrNot(int[] positions) {
    int catA = positions[0];
    int catB = positions[1];
    int mouse = positions[2];
    int catAFromMouse = Math.abs(catA - mouse);
    int catBFromMouse = Math.abs(catB - mouse);

    if (catAFromMouse < catBFromMouse) return "Cat A";
    if (catAFromMouse > catBFromMouse) return "Cat B";
    return "Mouse C";
}
