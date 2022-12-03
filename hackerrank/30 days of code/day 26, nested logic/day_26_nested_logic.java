import java.util.*;
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

class BookReturnDate {
    LocalDate returnedRealDate, dueDate;
    int fine;

    private void calculateFine() {
        if (returnedRealDate.compareTo(dueDate) <= 0)
            fine = 0;
        else if (returnedRealDate.getYear() == dueDate.getYear()) {
            if (returnedRealDate.getMonthValue() == dueDate.getMonthValue())
                fine = (returnedRealDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HackosFine.HackosDaysFine.getValue();
            else
                fine = (returnedRealDate.getMonthValue() - dueDate.getMonthValue()) * HackosFine.HackosMonthsFine.getValue();
        } else
            fine = HackosFine.HackosYearsFine.getValue();
    }

    public BookReturnDate(LocalDate returnedRealDate, LocalDate dueDate) {
        this.returnedRealDate = returnedRealDate;
        this.dueDate = dueDate;
        calculateFine();
    }

    public int getFine() {
        return fine;
    }
}

public class Execution {

    public static LocalDate[] readStdinDates() {
        Scanner reader = new Scanner(System.in);
        String[] line;
        int[] numbers;

        line = reader.nextLine().split(" ");
        numbers = Arrays.stream(line)
                  .mapToInt(Integer::parseInt)
                  .toArray();
        LocalDate returnedRealDate = LocalDate.of(numbers[2], numbers[1], numbers[0]);

        line = reader.nextLine().split(" ");
        numbers = Arrays.stream(line)
                  .mapToInt(Integer::parseInt)
                  .toArray();
        LocalDate dueDate = LocalDate.of(numbers[2], numbers[1], numbers[0]);

        LocalDate[] dates = {returnedRealDate, dueDate};
        return dates;
    }

    public static void main(String[] args) {
        LocalDate[] datesArray = readStdinDates();
        LocalDate returnedRealDate = datesArray[0], dueDate = datesArray[1];

        BookReturnDate bookReturnDateObj = new BookReturnDate(returnedRealDate, dueDate);
        System.out.println(bookReturnDateObj.getFine());
    }
}
