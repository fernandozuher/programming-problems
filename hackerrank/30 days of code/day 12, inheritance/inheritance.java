// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        final String firstName = scan.next();
        final String lastName = scan.next();
        final int id = scan.nextInt();
        final int nScores = scan.nextInt();

        final List<Integer> scores = Arrays.asList(new Integer[nScores])
                                     .stream()
                                     .map(x -> scan.nextInt())
                                     .collect(Collectors.toList());

        final Student student = new Student(firstName, lastName, id, scores);
        student.printPerson();
        System.out.println("Grade: " + student.calculate());
    }
}

    class Person {
        protected String firstName, lastName;
        protected int id;

        Person(String firstName, String lastName, int id) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.id = id;
        }

        public void printPerson() {
            System.out.println("Name: " + lastName + ", " + firstName +   "\nID: " + id);
        }
    }

        class Student extends Person {
            private List<Integer> scores;

            public Student(String firstName, String lastName, int id, List<Integer> scores) {
                super(firstName, lastName, id);
                this.scores = scores;
            }

            public char calculate() {
                final int avg = (int)scores.stream().mapToDouble(i -> i).average().orElse(0.0);

                if (avg >= 90 && avg <= 100)
                    return 'O';
                else if (avg >= 80 && avg < 90)
                    return 'E';
                else if (avg >= 70 && avg < 80)
                    return 'A';
                else if (avg >= 55 && avg < 70)
                    return 'P';
                else if (avg >= 40 && avg < 55)
                    return 'D';
                else
                    return 'T';
            }
        }
