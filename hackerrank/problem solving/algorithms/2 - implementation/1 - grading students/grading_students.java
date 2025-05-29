// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            List<Integer> grades = readNumbers(scan, n);
            List<Integer> roundedGrades = gradeStudents(grades);
            roundedGrades.forEach(System.out::println);
        }
    }

    private static List<Integer> readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).toList();
    }

    private static List<Integer> gradeStudents(List<Integer> grades) {
        final int minGrade = 38;
        return grades.stream().map(grade -> {
            if (grade < minGrade)
                return grade;
            int nextMultiple5 = (grade / 5 + 1) * 5;
            return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
        }).toList();
    }
}
