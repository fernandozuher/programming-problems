// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// From Java 21

import java.util.Scanner;
import java.util.List;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Main {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        List<Integer> records = breakingRecords(array);
        System.out.print(records.getFirst() + " " + records.getLast());
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static List<Integer> breakingRecords(List<Integer> scores) {
            int mostPoints = scores.getFirst(), leastPoints = scores.getFirst();
            int breakingMostPointsRecords = 0, breakingLeastPointsRecords = 0;

            for (int score : scores)
                if (score > mostPoints) {
                    mostPoints = score;
                    ++breakingMostPointsRecords;
                } else if (score < leastPoints) {
                    leastPoints = score;
                    ++breakingLeastPointsRecords;
                }

            return List.of(breakingMostPointsRecords, breakingLeastPointsRecords);
        }
}
