// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// Java 25

import java.lang.IO;

void main() {
    int n = readNumbers()[0];
    for (int i = 0; i < n; i++)
        IO.println(findNearestCatOrNot(readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

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
