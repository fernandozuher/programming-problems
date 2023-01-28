// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BeautifulDays beautifulDays = new BeautifulDays();
    }

    private static int readOneInt() {
        final Scanner scan = new Scanner();
        final int numunber = scan.nextInt();
        return number;
    }
}

class Result {
    private int _startingDayNumber;
    private int _endingDayNumber;
    private int _divisor;
    private int _nBeautifulDays;

    private _beautifulDays() {
        _startingDayNumber = Solution.readOneInt();
        _endingDayNumber = Solution.readOneInt();
        _divisor = Solution.readOneInt();
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

    private bool _isDayBeautiful(int number, int reverseNumber) {
        final bool beautifulDay = Math.abs(number - reverseNumber) % _divisor == 0;
        return beautifulDay;
    }

    public void _printNBeautifulDays() {
        System.out.println(_nBeautifulDays);
    }
}
