// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

import java.util.Scanner;
import java.time.LocalDate;

enum HackosFine {
    HackosDaysFine(15), HackosMonthsFine(500), HackosYearsFine(10000);

    private final int value;

    private HackosFine(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

public class LibraryFine {
    private static Scanner Scanner;

    public static void main(String[] args) {
        Scanner = new Scanner(System.in);

        final LocalDate RETURN_DATE = _readADate();
        final LocalDate DUE_DATE = _readADate();

        final int FINE = _calculateFine(RETURN_DATE, DUE_DATE);
        System.out.println(FINE);
    }

        private static LocalDate _readADate() {
            final int DAY = Scanner.nextInt();
            final int MONTH = Scanner.nextInt();
            final int YEAR = Scanner.nextInt();

            final LocalDate DATE = LocalDate.of(YEAR, MONTH, DAY);
            return DATE;
        }

        private static int _calculateFine(LocalDate returnDate, LocalDate dueDate) {
            int fine;

            if (_wereBooksReturnedInTime(returnDate, dueDate))
                fine = 0;
            else if (_isReturnDateLateInMoreThanOrEqualToOneYear(returnDate.getYear(), dueDate.getYear()))
                fine = HackosFine.HackosYearsFine.getValue();
            else if (_isReturnDateLateInMoreThanOrEqualToOneMonth(returnDate.getMonthValue(), dueDate.getMonthValue()))
                fine = (returnDate.getMonthValue() - dueDate.getMonthValue()) * HackosFine.HackosMonthsFine.getValue();
            else
                fine = (returnDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HackosFine.HackosDaysFine.getValue();

            return fine;
        }

            private static boolean _wereBooksReturnedInTime(LocalDate returnDate, LocalDate dueDate) {
                if ((returnDate.getYear() < dueDate.getYear()) ||
                        ((returnDate.getYear() == dueDate.getYear()) && (returnDate.getMonthValue() < dueDate.getMonthValue())) ||
                        ((returnDate.getYear() == dueDate.getYear()) && (returnDate.getMonthValue() == dueDate.getMonthValue()) && (returnDate.getDayOfMonth() <= dueDate.getDayOfMonth()))
                   )
                    return true;
                return false;
            }

            private static boolean _isReturnDateLateInMoreThanOrEqualToOneYear(int returnDateYear, int dueDateYear) {
                return returnDateYear > dueDateYear;
            }

            private static boolean _isReturnDateLateInMoreThanOrEqualToOneMonth(int returnDateMonth, int dueDateMonth) {
                return returnDateMonth > dueDateMonth;
            }
}
