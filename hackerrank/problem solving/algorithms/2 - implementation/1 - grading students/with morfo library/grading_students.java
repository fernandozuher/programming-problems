// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.io.Writer;

import java.util.List;

void main() {
    int n = Reader.read(Integer::parseInt);
    List<Integer> grades = Reader.read(n, Integer::parseInt);
    Writer.println(gradingStudents(grades));
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
List<Integer> gradingStudents(List<Integer> grades) {
    int minGrade = 38;
    for (int i = 0; i < grades.size(); i++) {
        int grade = grades.get(i);
        if (grade < minGrade) continue;
        int nextMultiple5 = (grade / 5 + 1) * 5;
        if (nextMultiple5 - grade < 3) grades.set(i, nextMultiple5);
    }
    return grades;
}
