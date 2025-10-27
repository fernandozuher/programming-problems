// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

void main() {
    int n = readNumbers(1)[0];
    int[] grades = readNumbers(n);
    int[] roundedGrades = gradeStudents(grades);
    Arrays.stream(roundedGrades).forEach(IO::println);
}

int[] readNumbers(int n) {
    return IntStream.range(0, n).map(_ -> Integer.parseInt(IO.readln())).toArray();
}

int[] gradeStudents(int[] grades) {
    final int minGrade = 38;
    return Arrays.stream(grades).map(grade -> {
        if (grade < minGrade) return grade;
        int nextMultiple5 = (grade / 5 + 1) * 5;
        return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
    }).toArray();
}
