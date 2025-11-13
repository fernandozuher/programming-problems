// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

void main() {
    int n = Integer.parseInt(IO.readln());
    for (int i = 0; i < n; i++) {
        int threshold = readNumbers()[1];
        int[] arrivalTimes = readNumbers();
        IO.println(angryProfessor(arrivalTimes, threshold) ? "YES" : "NO");
    }
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

boolean angryProfessor(int[] arrivalTimes, int threshold) {
    long count = Arrays.stream(arrivalTimes).filter(t -> t <= 0).count();
    return count < threshold;
}
