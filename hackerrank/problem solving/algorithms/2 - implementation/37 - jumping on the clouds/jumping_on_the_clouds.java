// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(minimumNumberOfJumps(readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int minimumNumberOfJumps(int[] clouds) {
    int jumps = 0;
    for (int i = 0, n = clouds.length - 1; i < n; i += nextJump(i, clouds))
        jumps++;
    return jumps;
}

int nextJump(int index, int[] clouds) {
    boolean isNextSecondCloudCumulus = false;
    if (index + 2 < clouds.length)
        isNextSecondCloudCumulus = clouds[index + 2] == 0;
    return isNextSecondCloudCumulus ? 2 : 1;
}
