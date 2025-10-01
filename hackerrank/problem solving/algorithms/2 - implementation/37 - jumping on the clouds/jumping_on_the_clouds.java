// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// Java 25

import java.util.*;
import java.lang.IO;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        IO.println(minimumNumberOfJumps(readNumbers(scan, n)));
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int minimumNumberOfJumps(int[] clouds) {
        int jumps = 0;
        for (int i = 0, n = clouds.length - 1; i < n; i += nextJump(i, clouds))
            jumps++;
        return jumps;
    }

    private static int nextJump(int index, int[] clouds) {
        boolean isNextSecondCloudCumulus = false;
        if (index + 2 < clouds.length)
            isNextSecondCloudCumulus = clouds[index + 2] == 0;
        return isNextSecondCloudCumulus ? 2 : 1;
    }
}
