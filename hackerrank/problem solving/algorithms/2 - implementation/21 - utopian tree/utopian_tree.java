// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.IntStream;

void main() {
    int n = Integer.parseInt(IO.readln());
    for (int i = 0; i < n; i++) {
        int cycles = Integer.parseInt(IO.readln());
        IO.println(utopianTree(cycles));
    }
}

int utopianTree(int cycles) {
    return IntStream.range(1, cycles + 1)
            .reduce(1, (height, cycle) -> isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1);
}

boolean isCycleHappeningDuringSpring(int cycle) {
    return (cycle & 1) == 1;
}
