// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int year = scan.nextInt();
            System.out.println(DayOfTheProgrammer.calculateDateOf256thDay(year));
        }
    }
}

class DayOfTheProgrammer {
    private static final int TRANSITION_YEAR = 1918;

    public static String calculateDateOf256thDay(int year) {
        String day;
        if (year == TRANSITION_YEAR)
            day = "26";
        else
            day = isLeapYear(year) ? "12" : "13";
        return day + ".09." + String.valueOf(year);
    }

    private static boolean isLeapYear(int year) {
        if (year < TRANSITION_YEAR)
            return isLeapJulianYear(year);
        if (year > TRANSITION_YEAR)
            return isLeapGregorianYear(year);
        return false;
    }

    private static boolean isLeapJulianYear(int year) {
        return year % 4 == 0;
    }

    private static boolean isLeapGregorianYear(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }
}
