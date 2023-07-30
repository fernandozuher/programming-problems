// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        final Scanner scan = new Scanner(System.in);

        for (int nTests = scan.nextInt(); nTests-- > 0;) {
            final int age = scan.nextInt();
            final Person p = new Person(age);
            p.amIOld();

            for (int j = 3; j-- > 0; p.yearPasses());
            p.amIOld();

            System.out.println();
        }
    }
}

    class Person {
        private int age;

        public Person(int initialAge) {
            if (initialAge < 0) {
                age = 0;
                System.out.println("Age is not valid, setting age to 0.");
            } else
                age = initialAge;
        }

        public void amIOld() {
            if (age < 13)
                System.out.println("You are young.");
            else if (age >= 13 && age < 18)
                System.out.println("You are a teenager.");
            else
                System.out.println("You are old.");
        }

        public void yearPasses() {
            ++age;
        }
    }
