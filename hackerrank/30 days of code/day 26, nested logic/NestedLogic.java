// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import java.util.stream.Collectors;
import java.time.LocalDate;

public class NestedLogic {
    public static void main(String[] args) {
        List<LocalDate> datesArray = readStdinDates();
        LocalDate returnedRealDate = datesArray.get(0), dueDate = datesArray.get(1);

        BookReturnDate bookReturnDateObj = new BookReturnDate(returnedRealDate, dueDate);
        System.out.println(bookReturnDateObj.fine());
    }

        private static List<LocalDate> readStdinDates() {
            Scanner scan = new Scanner(System.in);
            List<Integer> numbers = Arrays.asList(scan.nextLine().split(" ")).stream().map(x -> Integer.parseInt(x)).collect(Collectors.toList());
            LocalDate returnedRealDate = LocalDate.of(numbers.get(2), numbers.get(1), numbers.get(0));

            numbers = Arrays.asList(scan.nextLine().split(" ")).stream().map(x -> Integer.parseInt(x)).collect(Collectors.toList());
            LocalDate dueDate = LocalDate.of(numbers.get(2), numbers.get(1), numbers.get(0));

            List<LocalDate> dates = Stream.of(returnedRealDate, dueDate).collect(Collectors.toList());
            return dates;
        }
}

    class BookReturnDate {
        private LocalDate returnedRealDate, dueDate;
        private int fine;

        public BookReturnDate(final LocalDate returnedRealDate, final LocalDate dueDate) {
            this.returnedRealDate = returnedRealDate;
            this.dueDate = dueDate;
            calculateFine();
        }

            private void calculateFine() {
                if (returnedRealDate.compareTo(dueDate) <= 0)
                    fine = 0;
                else if (returnedRealDate.getYear() == dueDate.getYear()) {
                    if (returnedRealDate.getMonthValue() == dueDate.getMonthValue())
                        fine = (returnedRealDate.getDayOfMonth() - dueDate.getDayOfMonth()) * HackosFine.HackosDaysFine.fine();
                    else
                        fine = (returnedRealDate.getMonthValue() - dueDate.getMonthValue()) * HackosFine.HackosMonthsFine.fine();
                } else
                    fine = HackosFine.HackosYearsFine.fine();
            }

        public int fine() {
            return fine;
        }
    }

        enum HackosFine {
            HackosDaysFine(15), HackosMonthsFine(500), HackosYearsFine(10000);

            private final int fine;

            private HackosFine(int fine) {
                this.fine = fine;
            }

            public int fine() {
                return fine;
            }
        }
