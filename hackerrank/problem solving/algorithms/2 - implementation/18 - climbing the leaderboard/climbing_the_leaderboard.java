// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// Java 16

import java.util.*;
import java.util.stream.Stream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            scan.nextLine();
            List<Integer> ranked = removeDuplicates(readNumbers(scan));
            scan.nextLine();
            List<Integer> player = readNumbers(scan);
            climbingLeaderboard(ranked, player).forEach(System.out::println);
        }
    }

    private static List<Integer> readNumbers(Scanner scan) {
        return Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).toList();
    }

    private static List<Integer> removeDuplicates(List<Integer> numbers) {
        return numbers.stream().distinct().toList();
    }

    private static List<Integer> climbingLeaderboard(List<Integer> ranked, List<Integer> player) {
        List<Integer> playerRanks = Arrays.asList(new Integer[player.size()]);
        int i = ranked.size() - 1;

        for (int j = 0; j < player.size(); j++) {
            while (i >= 0 && player.get(j) >= ranked.get(i)) i--;
            playerRanks.set(j, i + 2);
        }

        return playerRanks;
    }
}
