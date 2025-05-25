// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            staircase(n);
        }
    }

    private static void staircase(int n) {
        for (int i = 1; i <= n; i++) {
            var spaces = " ".repeat(n - i);
            var hashes = "#".repeat(i);
            System.out.println(spaces + hashes);
        }
    }
}
