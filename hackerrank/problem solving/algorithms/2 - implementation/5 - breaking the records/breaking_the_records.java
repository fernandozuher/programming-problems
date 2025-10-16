// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        int[] scores = readNumbers(scan, n);
        int[] records = breakingRecords(scores);
        IO.println(records[0] + " " + records[1]);
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
