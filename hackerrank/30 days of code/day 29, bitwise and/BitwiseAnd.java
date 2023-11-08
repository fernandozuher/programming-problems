// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

import java.util.Scanner;

public class BitwiseAnd {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();

        while (n-- > 0) {
            int count = scan.nextInt();
            int lim = scan.nextInt();
            System.out.println(bitwiseAnd(count, lim));
        };
    }

        private static int bitwiseAnd(final int n, final int k) {
            int maximumValueLessThanK = 0;

            for (int i = 1; i <= n; ++i)
                for (int j = i + 1, operation; j <= n; ++j) {
                    operation = i & j;

                    if (operation < k && operation > maximumValueLessThanK) {
                        if (operation == k - 1)
                            return operation;
                        else
                            maximumValueLessThanK = operation;
                    }
                }

            return maximumValueLessThanK;
        }
}
