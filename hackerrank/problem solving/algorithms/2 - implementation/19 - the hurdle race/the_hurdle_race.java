// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import java.util.*;
import java.util.stream.Stream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int maxJump = readNumbers(scan)[1];
            int[] hurdles = readNumbers(scan);
            System.out.println(hurdleRace(hurdles, maxJump));
        }
    }

    private static int[] readNumbers(Scanner scan) {
        return Stream.of(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int hurdleRace(int[] hurdles, int maxJump) {
        return Math.max(0, Arrays.stream(hurdles).max().getAsInt() - maxJump);
    }
}
