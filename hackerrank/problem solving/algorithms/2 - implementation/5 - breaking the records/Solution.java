// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray();

        var records = new BreakingBestAndWorstRecords(array);
        System.out.println(records.mostPointsRecords() + " " + records.leastPointsRecords());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class BreakingBestAndWorstRecords {
        private List<Integer> scores;
        private int breakingMostPointsRecords, breakingLeastPointsRecords;

        public BreakingBestAndWorstRecords(final List<Integer> array) {
            scores = array;
            breakingMostPointsRecords = breakingLeastPointsRecords = 0;
            breakingRecords();
        }

            private void breakingRecords() {
                int mostPoints = scores.get(0);
                int leastPoints = scores.get(0);

                for (int score : scores)
                    if (score > mostPoints) {
                        mostPoints = score;
                        ++breakingMostPointsRecords;
                    } else if (score < leastPoints) {
                        leastPoints = score;
                        ++breakingLeastPointsRecords;
                    }
            }

        public int mostPointsRecords() {
            return breakingMostPointsRecords;
        }

        public int leastPointsRecords() {
            return breakingLeastPointsRecords;
        }
    }
