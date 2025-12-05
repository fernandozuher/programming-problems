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
    var nums = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    int day = nums[0];
    int month = nums[1];
    int year = nums[2];
    return LocalDate.of(year, month, day);
}

int calculateFine(LocalDate returnDate, LocalDate dueDate) {
    if (returnedOnTime(returnDate, dueDate)) return 0;
    if (returnDate.getYear() > dueDate.getYear()) return HACKOS_YEARS_FINE;
    if (returnDate.getMonthValue() > dueDate.getMonthValue())
        return (returnDate.getMonthValue() - dueDate.getMonthValue()) * HACKOS_MONTHS_FINE;
    return (returnDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HACKOS_DAYS_FINE;
}

boolean returnedOnTime(LocalDate returnDate, LocalDate dueDate) {
    return !returnDate.isAfter(dueDate);
}
