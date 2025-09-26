// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.Scanner;
import java.time.LocalDate;

class Solution {
    private static final int HACKOS_DAYS_FINE = 15;
    private static final int HACKOS_MONTHS_FINE = 500;
    private static final int HACKOS_YEARS_FINE = 10000;

    void main() {
        var scan = new Scanner(System.in);
        LocalDate returnDate = readDate(scan);
        LocalDate dueDate = readDate(scan);
        IO.println(calculateFine(returnDate, dueDate));
    }

    private static LocalDate readDate(Scanner scan) {
        int day = scan.nextInt();
        int month = scan.nextInt();
        int year = scan.nextInt();
        return LocalDate.of(year, month, day);
    }

    private static int calculateFine(LocalDate returnDate, LocalDate dueDate) {
        if (returnedOnTime(returnDate, dueDate)) return 0;
        if (returnDate.getYear() > dueDate.getYear()) return HACKOS_YEARS_FINE;
        if (returnDate.getMonthValue() > dueDate.getMonthValue())
            return (returnDate.getMonthValue() - dueDate.getMonthValue()) * HACKOS_MONTHS_FINE;
        return (returnDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HACKOS_DAYS_FINE;
    }

    private static boolean returnedOnTime(LocalDate returnDate, LocalDate dueDate) {
        return !returnDate.isAfter(dueDate);
    }
}
