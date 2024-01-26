// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> ranked = readIntArray();
        ranked = removeDuplicates(ranked);
        ranked.sort(Collections.reverseOrder());

        n = scan.nextInt();
        scan.nextLine();
        List<Integer> player = readIntArray();

        var obj = new ClimbingTheLeaderboard(ranked, player);
        obj.rank().forEach(System.out::println);
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }

        private static List<Integer> removeDuplicates(List<Integer> array) {
            var newArray = new HashSet<Integer>(array);
            array.clear();
            array.addAll(newArray);
            return array;
        }

    public static int binarySearchDescendingOrder(final List<Integer> array, final int low, final int high, final int key) {
        if (high >= low) {
            int middle = low + (high - low) / 2;

            if (key == array.get(middle))
                return middle;
            else if (key > array.get(middle))
                return binarySearchDescendingOrder(array, low, middle - 1, key);
            else
                return binarySearchDescendingOrder(array, middle + 1, high, key);
        }
        return low;
    }
}

    class ClimbingTheLeaderboard {
        private List<Integer> ranked;
        private List<Integer> player;
        private List<Integer> playerRank;

        public ClimbingTheLeaderboard(final List<Integer> ranked, final List<Integer> player) {
            this.ranked = ranked;
            this.player = player;
            playerRank = Arrays.asList(new Integer[player.size()]);
            climbingLeaderboard();
        }

            private void climbingLeaderboard() {
                for (int i = 0, lastIndex = ranked.size() - 1, n = player.size(); i < n; ++i) {
                    int index = Solution.binarySearchDescendingOrder(ranked, 0, lastIndex, player.get(i));
                    playerRank.set(i, ++index);
                }
            }

        public List<Integer> rank() {
            return playerRank;
        }
    }
