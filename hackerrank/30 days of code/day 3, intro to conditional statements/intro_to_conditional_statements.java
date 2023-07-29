// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int n = scanner.nextInt();

        if (n % 2 == 1 || n >= 6 && n <= 20)
            System.out.println("Weird");
        else
            System.out.println("Not Weird");
    }
}
