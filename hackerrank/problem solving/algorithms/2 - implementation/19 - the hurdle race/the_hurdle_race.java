// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// Java 25

void main() {
    int maxJump = readNumbers()[1];
    int[] hurdles = readNumbers();
    IO.println(hurdleRace(hurdles, maxJump));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array hurdles
// T: O(n)
// S: O(1) extra space
int hurdleRace(int[] hurdles, int maxJump) {
    return Math.max(0, Arrays.stream(hurdles).max().getAsInt() - maxJump);
}
