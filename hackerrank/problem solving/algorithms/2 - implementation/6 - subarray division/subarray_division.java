// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();

            int[] chocolateSquares = readNumbers(scan, n);
            final int nDayMonth = 2;
            int[] dayMonth = readNumbers(scan, nDayMonth);

            System.out.println(birthday(chocolateSquares, dayMonth));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int birthday(int[] chocolateSquares, int[] dayMonth) {
        int day = dayMonth[0];
        int month = dayMonth[1];

        if (month > chocolateSquares.length)
            return 0;

        int sum = Arrays.stream(chocolateSquares, 0, month).sum();
        int waysBarCanBeDivided = sum == day ? 1 : 0;

        for (int i = month; i < chocolateSquares.length; i++) {
            sum += chocolateSquares[i] - chocolateSquares[i - month];
            if (sum == day)
                waysBarCanBeDivided++;
        }

        return waysBarCanBeDivided;
    }
}
