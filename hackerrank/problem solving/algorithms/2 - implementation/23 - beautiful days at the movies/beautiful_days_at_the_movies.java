// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import java.io.*;
import java.util.*;


public class Solution {

    private static Scanner _scan;

    public static void main(String[] args) {
         _scan = new Scanner(System.in);

        final int startingDayNumber = _readOneInt();
        final int endingDayNumber = _readOneInt();
        final int divisor = _readOneInt();

        final BeautifulDays beautifulDays = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
    }

        private static int _readOneInt() {
            final int number = _scan.nextInt();
            return number;
        }
}

    class BeautifulDays {

        private int _startingDayNumber;
        private int _endingDayNumber;
        private int _divisor;
        private int _nBeautifulDays;

        public BeautifulDays(int startingDayNumber, int endingDayNumber, int divisor) {
            _startingDayNumber = startingDayNumber;
            _endingDayNumber = endingDayNumber;
            _divisor = divisor;
            _nBeautifulDays = 0;

            _beautifulDays();
            printNBeautifulDays();
        }

            private void _beautifulDays() {
                for (int number = _startingDayNumber; number <= _endingDayNumber; number++) {
                    final int reverseNumber = _generateReverseNumber(number);

                    if (_isDayBeautiful(number, reverseNumber))
                        _nBeautifulDays++;
                }
            }

                private int _generateReverseNumber(int number) {
                    int reverseNumber = 0;
                    for (; number > 0; number /= 10)
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }

                private boolean _isDayBeautiful(int number, int reverseNumber) {
                    final boolean beautifulDay = Math.abs(number - reverseNumber) % _divisor == 0;
                    return beautifulDay;
                }

            public void printNBeautifulDays() {
                System.out.println(_nBeautifulDays);
            }
    }
