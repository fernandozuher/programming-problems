// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

void main() {
    int jumpLength = readNumbers()[1];
    int[] arr = readNumbers();
    IO.println(jumpingOnTheClouds(arr, jumpLength));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int jumpingOnTheClouds(int[] clouds, int jumpLength) {
    int energy = 100;
    int cloudIndex = 0;

    do {
        energy -= clouds[cloudIndex] == 0 ? 1 : 3;
        cloudIndex = (cloudIndex + jumpLength) % clouds.length;
    } while (cloudIndex != 0);

    return energy;
}
