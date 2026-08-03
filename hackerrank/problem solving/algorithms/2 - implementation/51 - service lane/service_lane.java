// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// Java 25

void main() {
    int t = readNums()[1];
    int[] widths = readNums();
    for (int i = 0; i < t; i++)
        IO.println(minWidthInSegment(widths, readNums()));
}

int[] readNums() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment) {
    int start = segment[0], finish = segment[1];
    return Arrays.stream(widths, start, finish + 1).min().getAsInt();
}
