// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        int maximumHeightCanJump = scan.nextInt();
        scan.nextLine();
        List<Integer> hurdlesHeights = readIntArray();

        var obj = new HurdleRace(hurdlesHeights, maximumHeightCanJump);
        System.out.println(obj.doses());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class HurdleRace {
        private List<Integer> hurdlesHeights;
        private int maximumHeightCanJump;
        private int n_doses;

        public HurdleRace(final List<Integer> hurdlesHeights, final int maximumHeightCanJump) {
            this.hurdlesHeights = hurdlesHeights;
            this.maximumHeightCanJump = maximumHeightCanJump;
            n_doses = 0;
            hurdleRace();
        }

            private void hurdleRace() {
                int highestHurdle = Collections.max(hurdlesHeights);
                n_doses = highestHurdle > maximumHeightCanJump ? highestHurdle - maximumHeightCanJump : 0;
            }

        public int doses() {
            return n_doses;
        }
    }
