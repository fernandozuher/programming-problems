// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// From Java 16

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Main {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        gradingStudents(array).forEach(System.out::println);
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.stream(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static List<Integer> gradingStudents(final List<Integer> grades) {
            int n = grades.size();
            List<Integer> newGrades = Arrays.asList(new Integer[n]);

            for (int i = 0, minGrade = 38; i < n; ++i) {
                if (grades.get(i) < minGrade || isZeroRemainder(grades.get(i)))
                    newGrades.set(i, grades.get(i));
                else {
                    int quotient = grades.get(i) / 5;
                    int nextMultiple5 = (quotient + 1) * 5;
                    int difference = nextMultiple5 - grades.get(i);
                    int result = difference < 3 ? nextMultiple5 : grades.get(i);
                    newGrades.set(i, result);
                }
            }

            return newGrades;
        }

            public static boolean isZeroRemainder(final int grade) {
                return grade % 5 == 0;
            }
}
