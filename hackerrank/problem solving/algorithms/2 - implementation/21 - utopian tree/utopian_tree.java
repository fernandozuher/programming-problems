// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            utopianTree(readNumbers(scan, n)).forEach(System.out::println);
        }
    }

    private static List<Integer> readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).toList();
    }

    private static List<Integer> utopianTree(List<Integer> testCases) {
        return testCases.stream().map(Solution::calculateHeight).toList();
    }

    private static int calculateHeight(int cycles) {
        return IntStream.range(1, cycles + 1)
                .reduce(1, (height, cycle) ->
                        isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1);
    }

    private static boolean isCycleHappeningDuringSpring(int cycle) {
        return (cycle & 1) == 1;
    }
}
