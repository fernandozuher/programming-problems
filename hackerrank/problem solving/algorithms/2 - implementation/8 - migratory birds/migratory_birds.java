// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            int[] birds = readNumbers(scan, n);
            System.out.println(findMostSpottedBird(birds));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int findMostSpottedBird(int[] birds) {
        var birdCount = new HashMap<Integer, Integer>();
        for (int bird : birds) {
            birdCount.put(bird, birdCount.getOrDefault(bird, 0) + 1);
        }
        return birdCount.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();
    }
}
