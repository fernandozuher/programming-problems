// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.Stream;

class Solution {
    void main() {
        IO.readln();
        Map<Integer, Integer> birdCounts = countNumbersIntoHash();
        IO.println(findMostSpottedBird(birdCounts));
    }

    private static Map<Integer, Integer> countNumbersIntoHash() {
        Map<Integer, Integer> numberCounts = new HashMap<>();
        Stream.of(IO.readln().split(" ")).map(Integer::parseInt).forEach(x ->
                numberCounts.put(x, numberCounts.getOrDefault(x, 0) + 1)
        );
        return numberCounts;
    }

    private static int findMostSpottedBird(Map<Integer, Integer> birdCounts) {
        return birdCounts.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();
    }
}
