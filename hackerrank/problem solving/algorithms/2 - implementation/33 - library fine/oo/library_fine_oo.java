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

public class Solution {
    private static Scanner Scanner;

    public static void main(String[] args) {
        Scanner = new Scanner(System.in);

        final LocalDate RETURN_DATE = _readADate();
        final LocalDate DUE_DATE = _readADate();

        final LibraryFine OBJ = new LibraryFine(RETURN_DATE, DUE_DATE);
        final int FINE = OBJ.getFine();
        System.out.println(FINE);
    }

    private static LocalDate _readADate() {
        final int DAY = Scanner.nextInt();
        final int MONTH = Scanner.nextInt();
        final int YEAR = Scanner.nextInt();

        final LocalDate DATE = LocalDate.of(YEAR, MONTH, DAY);
        return DATE;
    }
}

    class LibraryFine {
        private final LocalDate _RETURN_DATE;
        private final LocalDate _DUE_DATE;
        private int _fine;

        public LibraryFine(LocalDate returnDate, LocalDate dueDate) {
            _RETURN_DATE = returnDate;
            _DUE_DATE = dueDate;
            _fine = 0;

            _calculateFine();
        }

            private void _calculateFine() {
                if (_wereBooksReturnedInTime())
                    _fine = 0;
                else if (_isReturnDateLateInMoreThanOrEqualToOneYear())
                    _fine = HackosFine.HackosYearsFine.getValue();
                else if (_isReturnDateLateInMoreThanOrEqualToOneMonth())
                    _fine = (_RETURN_DATE.getMonthValue() - _DUE_DATE.getMonthValue()) * HackosFine.HackosMonthsFine.getValue();
                else
                    _fine = (_RETURN_DATE.getDayOfMonth() - _DUE_DATE.getDayOfMonth()) * HackosFine.HackosDaysFine.getValue();
            }

                private boolean _wereBooksReturnedInTime() {
                    if ((_RETURN_DATE.getYear() < _DUE_DATE.getYear()) ||
                            ((_RETURN_DATE.getYear() == _DUE_DATE.getYear()) && (_RETURN_DATE.getMonthValue() < _DUE_DATE.getMonthValue())) ||
                            ((_RETURN_DATE.getYear() == _DUE_DATE.getYear()) && (_RETURN_DATE.getMonthValue() == _DUE_DATE.getMonthValue()) && (_RETURN_DATE.getDayOfMonth() <= _DUE_DATE.getDayOfMonth()))
                       )
                        return true;
                    return false;
                }

                private boolean _isReturnDateLateInMoreThanOrEqualToOneYear() {
                    return _RETURN_DATE.getYear() > _DUE_DATE.getYear();
                }

                private boolean _isReturnDateLateInMoreThanOrEqualToOneMonth() {
                    return _RETURN_DATE.getMonthValue() > _DUE_DATE.getMonthValue();
                }

        public int getFine() {
            return _fine;
        }
    }
