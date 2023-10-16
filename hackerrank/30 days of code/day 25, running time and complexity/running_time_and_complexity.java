// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);

        for (int n = scan.nextInt(); n-- > 0;) {
            int number = scan.nextInt();

            if (number == 1) {
                System.out.println("Not prime");
                continue;
            }

            int i = 2, limit = (int) Math.sqrt(number);
            for (; i <= limit; ++i)
                if (number % i == 0) {
                    System.out.println("Not prime");
                    break;
                }

            if (i > limit)
                System.out.println("Prime");
        }
    }
}
