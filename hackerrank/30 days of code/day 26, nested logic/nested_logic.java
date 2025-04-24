// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

import java.util.*;
import java.time.LocalDate;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            LocalDate returnedDate = readDate(scan);
            LocalDate dueDate = readDate(scan);
            int fine = !returnedDate.isAfter(dueDate) ? 0 : new FineOnDelay(returnedDate, dueDate).fine();
            System.out.println(fine);
        }
    }

    private static LocalDate readDate(Scanner scan) {
        var dateParts = Arrays.stream(scan.nextLine().split(" ")).map(Integer::parseInt).toArray();
        int day = (int) dateParts[0], month = (int) dateParts[1], year = (int) dateParts[2];
        return LocalDate.of(year, month, day);
    }
}

class FineOnDelay {
    private static final int FINE_PER_YEAR = 10000;
    private static final int FINE_PER_MONTH = 500;
    private static final int FINE_PER_DAY = 15;

    private final LocalDate returnedDate;
    private final LocalDate dueDate;
    private final int fineValue;

    public FineOnDelay(LocalDate returnedDate, LocalDate dueDate) {
        this.returnedDate = returnedDate;
        this.dueDate = dueDate;
        fineValue = calculateFine();
    }

    private int calculateFine() {
        int fine = lateByYear();
        if (fine != 0)
            return fine;

        fine = lateByMonth();
        if (fine != 0)
            return fine;

        return lateByDay();
    }

    private int lateByYear() {
        if (returnedDate.getYear() > dueDate.getYear())
            return FINE_PER_YEAR;
        return 0;
    }

    private int lateByMonth() {
        if (isSameYear() && returnedDate.getMonthValue() > dueDate.getMonthValue())
            return (returnedDate.getMonthValue() - dueDate.getMonthValue()) * FINE_PER_MONTH;
        return 0;
    }

    private boolean isSameYear() {
        return returnedDate.getYear() == dueDate.getYear();
    }

    private int lateByDay() {
        if (isSameYear() && isSameMonth() && returnedDate.getDayOfMonth() > dueDate.getDayOfMonth())
            return (returnedDate.getDayOfMonth() - dueDate.getDayOfMonth()) * FINE_PER_DAY;
        return 0;
    }

    private boolean isSameMonth() {
        return returnedDate.getMonthValue() == dueDate.getMonthValue();
    }

    public int fine() {
        return fineValue;
    }
}
