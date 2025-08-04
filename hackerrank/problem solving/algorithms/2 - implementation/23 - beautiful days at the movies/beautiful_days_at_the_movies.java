// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int startDay = scan.nextInt();
            int endDay = scan.nextInt();
            int divisor = scan.nextInt();
            System.out.println(beautifulDays(startDay, endDay, divisor));
        }
    }

    private static int beautifulDays(int startDay, int endDay, int divisor) {
        return (int) IntStream.range(startDay, endDay + 1).filter(day -> isDayBeautiful(day, divisor)).count();
    }

    private static boolean isDayBeautiful(int day, int divisor) {
        return Math.abs(day - reverseNumber(day)) % divisor == 0;
    }

    private static int reverseNumber(int number) {
        return Integer.parseInt(new StringBuilder(String.valueOf(number)).reverse().toString());
    }
}
