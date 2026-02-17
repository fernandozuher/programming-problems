// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// Java 25

void main() {
    int t = readNumbers()[1];
    int[] widths = readNumbers();
    for (int i = 0; i < t; i++)
        IO.println(minWidthInSegment(widths, readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment) {
    return Arrays.stream(widths, segment[0], segment[1] + 1).min().getAsInt();
}
