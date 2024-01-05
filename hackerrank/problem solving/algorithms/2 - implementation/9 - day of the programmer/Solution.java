// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int year = scan.nextInt();
        var obj = new DayOfTheProgrammer(year);
        System.out.println(obj.date());
    }
}

    class DayOfTheProgrammer {
        private static int TRANSITION_YEAR = 1918;
        private int year;
        private String dateOf256thDay;

        public DayOfTheProgrammer(final int year) {
            this.year = year;
            dateOf256thDay = "";
            findDateOf256thDay();
        }

            private void findDateOf256thDay() {
                findDayMonthOf256thDay();
                dateOf256thDay += String.valueOf(year);
            }

                private void findDayMonthOf256thDay() {
                    if (year != TRANSITION_YEAR)
                        dateOf256thDay = isLeapYear() ? "12.09." : "13.09.";
                    else
                        dateOf256thDay = "26.09.";
                }

                    private boolean isLeapYear() {
                        return year > TRANSITION_YEAR ? isLeapGregorianYear() : isLeapJulianYear();
                    }

                        private boolean isLeapGregorianYear() {
                            return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
                        }

                        private boolean isLeapJulianYear() {
                            return year % 4 == 0;
                        }

        public String date() {
            return dateOf256thDay;
        }
    }
