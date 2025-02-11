// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

import java.util.Scanner;

public class IntroToConditionalStatements {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        boolean isWeird = n % 2 == 1 || n >= 6 && n <= 20;
        System.out.println(isWeird ? "Weird" : "Not Weird");
    }
}
