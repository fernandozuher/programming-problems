// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// Java 25

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

// k: length of array arrivalTimes
// T: O(k)
// S: O(1) extra space
boolean angryProfessor(int[] arrivalTimes, int threshold) {
    long onTime = Arrays.stream(arrivalTimes).filter(t -> t <= 0).count();
    return onTime < threshold;
}
