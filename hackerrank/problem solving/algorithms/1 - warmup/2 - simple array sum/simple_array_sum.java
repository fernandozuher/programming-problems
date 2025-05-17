// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            System.out.print(sumStdin(scan, n));
        }
    }

    private static int sumStdin(Scanner scan, int n) {
        int sum = 0;
        while (n-- > 0)
            sum += scan.nextInt();
        return sum;
    }
}
