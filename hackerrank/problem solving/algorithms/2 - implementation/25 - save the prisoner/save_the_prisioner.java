// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

// n = test cases
// T = O(n)
// S = O(1)
void main() {
    int n = readNumbers()[0];
    for (int i = 0; i < n; i++) {
        var line = readNumbers();
        int prisoners = line[0];
        int sweets = line[1];
        int startChair = line[2];
        IO.println(saveThePrisoner(prisoners, sweets, startChair));
    }
}

// n = size of elements to be read
// T = O(n)
// S = O(n)
int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// T = O(1)
// S = O(1)
int saveThePrisoner(int prisoners, int sweets, int startChair) {
    return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
