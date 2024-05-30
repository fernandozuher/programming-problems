// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(aVeryBigSum(n));
    }

        public static long aVeryBigSum(int n) {
            long sum = 0;
            while (n-- > 0)
                sum += scan.nextInt();
            return sum;
        }
}
