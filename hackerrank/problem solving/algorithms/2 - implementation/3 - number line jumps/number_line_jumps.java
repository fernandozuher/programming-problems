// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// Java 25

void main() {
    final int n = 4;
    int[] positionsAndVelocities = readNumbers();
    IO.println(kangaroo(positionsAndVelocities) ? "YES" : "NO");
}

private static int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).map(Integer::parseInt).toArray();
}

private static boolean kangaroo(int[] positionsAndVelocities) {
    int x1 = positionsAndVelocities[0];
    int v1 = positionsAndVelocities[1];
    int x2 = positionsAndVelocities[2];
    int v2 = positionsAndVelocities[3];

    if (v1 == v2) return x1 == x2;

    int distanceDiff = x2 - x1;
    int velocityDiff = v1 - v2;
    return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff == 0;
}
