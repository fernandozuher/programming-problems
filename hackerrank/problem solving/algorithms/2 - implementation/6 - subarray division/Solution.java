// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// From Java 21

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
        List<Integer> chocolateSquares = readIntArray(n);
        final int nDayMonth = 2;
        List<Integer> dayMonth = readIntArray(nDayMonth);
        System.out.println(birthday(chocolateSquares, dayMonth));
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static int birthday(List<Integer> chocolateSquares, List<Integer> dayMonth) {
            int waysBarCanBeDivided = 0;
            int day = dayMonth.getFirst();
            int month = dayMonth.getLast();

            for (int i = 0, n = chocolateSquares.size() - month + 1; i < n; ++i) {
                int sum = chocolateSquares.subList(i, i + month).stream().mapToInt(Integer::intValue).sum();
                if (sum == day) ++waysBarCanBeDivided;
            }

            return waysBarCanBeDivided;
        }
}
