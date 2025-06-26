// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            Map<Integer, Integer> birdCounts = countNumbersIntoHash(scan, n);
            System.out.println(findMostSpottedBird(birdCounts));
        }
    }

    private static Map<Integer, Integer> countNumbersIntoHash(Scanner scan, int n) {
        Map<Integer, Integer> numberCounts = new HashMap<>();
        while (n-- > 0) {
            int x = scan.nextInt();
            numberCounts.put(x, numberCounts.getOrDefault(x, 0) + 1);
        }
        return numberCounts;
    }

    private static int findMostSpottedBird(Map<Integer, Integer> birdCounts) {
        return birdCounts.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();
    }
}
