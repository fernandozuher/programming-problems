// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int startingDayNumber = scan.nextInt();
        int endingDayNumber = scan.nextInt();
        int divisor = scan.nextInt();

        var obj = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
        System.out.println(obj.nBeautifulDays());
    }
}

    class BeautifulDays {
        private int startingDayNumber;
        private int endingDayNumber;
        private int divisor;
        private int beautifulDaysQuantity;

        public BeautifulDays(final int startingDayNumber, final int endingDayNumber, final int divisor) {
            this.startingDayNumber = startingDayNumber;
            this.endingDayNumber = endingDayNumber;
            this.divisor = divisor;
            beautifulDaysQuantity = 0;
            calculateBeautifulDaysQuantity();
        }

            private void calculateBeautifulDaysQuantity() {
                for (int number = startingDayNumber; number <= endingDayNumber; ++number) {
                    int reverseNumber = generateReverseNumber(number);
                    if (isDayBeautiful(number, reverseNumber))
                        ++beautifulDaysQuantity;
                }
            }

                private int generateReverseNumber(int number) {
                    int reverseNumber = 0;
                    for (; number > 0; number /= 10)
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                private boolean isDayBeautiful(final int number, final int reverseNumber) {
                    return Math.abs(number - reverseNumber) % divisor == 0;
                }

        public int nBeautifulDays() {
            return beautifulDaysQuantity;
        }
    }
