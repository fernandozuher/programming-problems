// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import java.lang.IO;
import java.util.*;
import java.util.stream.Stream;

void main() {
    int maxJump = readNumbers()[1];
    int[] hurdles = readNumbers();
    IO.println(hurdleRace(hurdles, maxJump));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int hurdleRace(int[] hurdles, int maxJump) {
    return Math.max(0, Arrays.stream(hurdles).max().getAsInt() - maxJump);
}
