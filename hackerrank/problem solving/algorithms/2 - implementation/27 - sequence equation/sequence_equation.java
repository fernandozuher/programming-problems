// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

void main() {
    IO.readln();
    int[] arr = readNumbers();
    for (int x : sequenceEquation(arr))
        IO.println(x);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int[] sequenceEquation(int[] arr) {
    int[] valuesToIndex = new int[arr.length];
    int i = 0;
    for (int val : arr) {
        valuesToIndex[val - 1] = i++;
    }

    int[] res = new int[arr.length];
    i = 0;
    for (int val : valuesToIndex) {
        res[i++] = valuesToIndex[val] + 1;
    }

    return res;
}
