// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

import java.util.Scanner;

public class Staircase {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        staircase(n);
    }

        private static void staircase(final int n) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < n - i; ++j)
                    System.out.print(" ");
                for (int k = 0; k < i; ++k)
                    System.out.print("#");
                System.out.print("\n");
            }
        }
}
