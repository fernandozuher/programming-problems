// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true
// Java 25

final int HACKOS_DAYS_FINE = 15;
final int HACKOS_MONTHS_FINE = 500;
final int HACKOS_YEARS_FINE = 10000;

void main() {
    LocalDate returnDate = readDate();
    LocalDate dueDate = readDate();
    IO.println(calculateFine(returnDate, dueDate));
}

LocalDate readDate() {
    var arr = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    int day = arr[0];
    int month = arr[1];
    int year = arr[2];
    return LocalDate.of(year, month, day);
}

// T: O(1)
// S: O(1) extra space
int calculateFine(LocalDate returnDate, LocalDate dueDate) {
    if (isYearLate(returnDate, dueDate)) return HACKOS_YEARS_FINE;
    if (isMonthLate(returnDate, dueDate))
        return (returnDate.getMonthValue() - dueDate.getMonthValue()) * HACKOS_MONTHS_FINE;
    if (isDayLate(returnDate, dueDate))
        return (returnDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HACKOS_DAYS_FINE;
    return 0;
}

boolean isYearLate(LocalDate returnDate, LocalDate dueDate) {
    return returnDate.getYear() > dueDate.getYear();
}

boolean isMonthLate(LocalDate returnDate, LocalDate dueDate) {
    return returnDate.getYear() == dueDate.getYear() && returnDate.getMonthValue() > dueDate.getMonthValue();
}

boolean isDayLate(LocalDate returnDate, LocalDate dueDate) {
    return returnDate.getYear() == dueDate.getYear() && returnDate.getMonthValue() == dueDate.getMonthValue() && returnDate.getDayOfMonth() > dueDate.getDayOfMonth();
}
