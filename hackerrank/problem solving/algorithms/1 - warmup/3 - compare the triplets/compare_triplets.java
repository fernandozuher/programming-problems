// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            final int n = 3;
            int[] tripletA = readInput(scan, n);
            int[] tripletB = readInput(scan, n);
            int[] result = compareTriplets(tripletA, tripletB);
            System.out.println(result[0] + " " + result[1]);
        }
    }

    private static int[] readInput(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int[] compareTriplets(int[] tripletA, int[] tripletB) {
        int scoreA = 0, scoreB = 0;

        for (int i = 0; i < tripletA.length; i++) {
            if (tripletA[i] > tripletB[i])
                ++scoreA;
            else if (tripletB[i] > tripletA[i])
                ++scoreB;
        }

        return new int[]{scoreA, scoreB};
    }
}
