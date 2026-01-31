// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(minJumps(readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
int minJumps(int[] clouds) {
    int jumps = 0;
    for (int i = 0, n = clouds.length - 1; i < n; i += skip(i, clouds), jumps++);
    return jumps;
}

int skip(int idx, int[] clouds) {
    return isNextSecondCloudCumulus(idx, clouds) ? 2 : 1;
}

boolean isNextSecondCloudCumulus(int idx, int[] clouds) {
    return idx + 2 < clouds.length && clouds[idx + 2] == 0;
}
