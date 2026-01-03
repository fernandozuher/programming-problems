// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// Java 25

void main() {
    int n = readNumbers(1)[0];
    int[] grades = readNumbers(n);
    for (int x : gradingStudents(grades))
        IO.println(x);
}

int[] readNumbers(int n) {
    return IntStream.range(0, n).map(_ -> Integer.parseInt(IO.readln())).toArray();
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
int[] gradingStudents(int[] grades) {
    for (int i = 0, minGrade = 38; i < grades.length; i++) {
        if (grades[i] >= minGrade) {
            int nextMultiple5 = (grades[i] / 5 + 1) * 5;
            if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
        }
    }
    return grades;
}