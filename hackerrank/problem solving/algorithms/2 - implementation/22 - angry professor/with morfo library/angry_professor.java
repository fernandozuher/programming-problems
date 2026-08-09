// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++) {
        Reader.skipInput();
        int threshold = Reader.read(Integer::parseInt);
        int[] arrivalTimes = Reader.readLnInts();
        IO.println(angryProfessor(arrivalTimes, threshold) ? "YES" : "NO");
    }
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
boolean angryProfessor(int[] arrivalTimes, int threshold) {
    long onTime = Arrays.stream(arrivalTimes).filter(t -> t <= 0).count();
    return onTime < threshold;
}
