// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true
// From Java 21: _ unnamed variable

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        var data = readInput();
        var student = new Student(data.personalData(), data.studentData());
        student.printPerson();
        System.out.println("Grade: " + student.calculate_grade());
    }

    private static PersonalAndStudentData readInput() {
        String firstName = scan.next();
        String lastName = scan.next();
        int id = scan.nextInt();
        int nScores = scan.nextInt();
        var scores = Arrays.stream(new Integer[nScores]).map(_ -> scan.nextInt()).toList();
        return new PersonalAndStudentData(new PersonalData(firstName, lastName, id), new StudentData(scores));
    }
}

record PersonalAndStudentData(PersonalData personalData, StudentData studentData) {
}

record PersonalData(String firstName, String lastName, int id) {
}

record StudentData(List<Integer> scores) {
}

class Person {
    private String firstName, lastName;
    private int id;

    Person(PersonalData data) {
        this.firstName = data.firstName();
        this.lastName = data.lastName();
        this.id = data.id();
    }

    public void printPerson() {
        System.out.println("Name: " + lastName + ", " + firstName + "\nID: " + id);
    }
}

class Student extends Person {
    private List<Integer> scores;

    public Student(PersonalData personalData, StudentData studentData) {
        super(personalData);
        this.scores = studentData.scores();
    }

    public char calculate_grade() {
        int avg = (int) scores.stream().mapToInt(i -> i).average().orElse(0);

        if (avg > 100 || avg < 40)
            return 'T';
        else if (avg >= 90)
            return 'O';
        else if (avg >= 80)
            return 'E';
        else if (avg >= 70)
            return 'A';
        else if (avg >= 55)
            return 'P';
        return 'D';
    }
}
