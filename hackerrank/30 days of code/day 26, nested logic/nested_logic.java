// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

import java.util.*;
import java.time.LocalDate;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            LocalDate returnedRealDate = readDate(scan);
            LocalDate dueDate = readDate(scan);
            if (!returnedRealDate.isAfter(dueDate))
                System.out.println(0);
            else
                System.out.println(new FineOnDelay(returnedRealDate, dueDate).fine());
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

    private final LocalDate returnedRealDate;
    private final LocalDate dueDate;
    private int fineValue;

    public FineOnDelay(LocalDate returnedRealDate, LocalDate dueDate) {
        this.returnedRealDate = returnedRealDate;
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
        if (returnedRealDate.getYear() > dueDate.getYear())
            return FINE_PER_YEAR;
        return 0;
    }

    private int lateByMonth() {
        if (returnedRealDate.getYear() == dueDate.getYear() && returnedRealDate.getMonthValue() > dueDate.getMonthValue())
            return (returnedRealDate.getMonthValue() - dueDate.getMonthValue()) * FINE_PER_MONTH;
        return 0;
    }

    private int lateByDay() {
        if (returnedRealDate.getYear() == dueDate.getYear()
                && returnedRealDate.getMonthValue() == dueDate.getMonthValue()
                && returnedRealDate.getDayOfMonth() > dueDate.getDayOfMonth())
            return (returnedRealDate.getDayOfMonth() - dueDate.getDayOfMonth()) * FINE_PER_DAY;
        return 0;
    }

    public int fine() {
        return fineValue;
    }
}
