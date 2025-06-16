// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            int[] scores = readNumbers(scan, n);
            int[] records = breakingRecords(scores);
            System.out.print(records[0] + " " + records[1]);
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int[] breakingRecords(int[] scores) {
        int mostPoints = scores[0], leastPoints = scores[0];
        int mostRecordBreaks = 0, leastRecordBreaks = 0;

        for (int score : scores)
            if (score > mostPoints) {
                mostPoints = score;
                mostRecordBreaks++;
            } else if (score < leastPoints) {
                leastPoints = score;
                leastRecordBreaks++;
            }

        return new int[]{mostRecordBreaks, leastRecordBreaks};
    }
}
