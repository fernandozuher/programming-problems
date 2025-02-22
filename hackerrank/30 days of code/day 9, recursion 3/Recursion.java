// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

import java.util.Scanner;

public class Recursion {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(factorial(n));
    }

    private static int factorial(int n) {
        return n == 1 ? 1 : n * factorial(n - 1);
    }
}
