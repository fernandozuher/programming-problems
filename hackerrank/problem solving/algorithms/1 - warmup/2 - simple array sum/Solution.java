// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.print(simpleArraySum(n));
    }

        public static int simpleArraySum(int n) {
            int sum = 0;
            while (n-- > 0)
                sum += scan.nextInt();
            return sum;
        }
}
