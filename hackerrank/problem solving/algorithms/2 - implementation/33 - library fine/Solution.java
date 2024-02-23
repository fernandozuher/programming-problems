// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

import java.util.Scanner;
import java.time.LocalDate;

enum HackosFine {
    HackosDaysFine(15), HackosMonthsFine(500), HackosYearsFine(10000);

    private final int enumValue;

    private HackosFine(int value) {
        this.enumValue = value;
    }

    public int value() {
        return enumValue;
    }
}

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        LocalDate returnDate = readADate();
        LocalDate dueDate = readADate();
        var obj = new LibraryFine(returnDate, dueDate);
        System.out.println(obj.fine());
    }

        public static LocalDate readADate() {
            int day = scan.nextInt();
            int month = scan.nextInt();
            int year = scan.nextInt();
            return LocalDate.of(year, month, day);
        }
}

    class LibraryFine {
        private final LocalDate returnDate;
        private final LocalDate dueDate;
        private int fineAmount;

        public LibraryFine(final LocalDate returnDate, final LocalDate dueDate) {
            this.returnDate = returnDate;
            this.dueDate = dueDate;
            fineAmount = 0;
            calculateFine();
        }

            private void calculateFine() {
                if (wereBooksReturnedInTime())
                    fineAmount = 0;
                else if (isReturnDateLateInMoreThanOrEqualToOneYear())
                    fineAmount = HackosFine.HackosYearsFine.value();
                else if (isReturnDateLateInMoreThanOrEqualToOneMonth())
                    fineAmount = (returnDate.getMonthValue() - dueDate.getMonthValue()) * HackosFine.HackosMonthsFine.value();
                else
                    fineAmount = (returnDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HackosFine.HackosDaysFine.value();
            }

                private boolean wereBooksReturnedInTime() {
                    if ((returnDate.getYear() < dueDate.getYear()) ||
                            ((returnDate.getYear() == dueDate.getYear()) && (returnDate.getMonthValue() < dueDate.getMonthValue())) ||
                            ((returnDate.getYear() == dueDate.getYear()) && (returnDate.getMonthValue() == dueDate.getMonthValue()) && (returnDate.getDayOfMonth() <= dueDate.getDayOfMonth()))
                       )
                        return true;
                    return false;
                }

                private boolean isReturnDateLateInMoreThanOrEqualToOneYear() {
                    return returnDate.getYear() > dueDate.getYear();
                }

                private boolean isReturnDateLateInMoreThanOrEqualToOneMonth() {
                    return returnDate.getMonthValue() > dueDate.getMonthValue();
                }

        public int fine() {
            return fineAmount;
        }
    }
