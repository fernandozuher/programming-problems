// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            final int n = 4;
            int[] positionsAndVelocities = readNumbers(scan, n);
            System.out.println(kangaroo(positionsAndVelocities) ? "YES" : "NO");
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
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
}
