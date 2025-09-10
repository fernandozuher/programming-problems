// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

import java.math.BigInteger;
import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            System.out.println(factorial(n));
        }
    }

    private static BigInteger factorial(int n) {
        BigInteger res = BigInteger.ONE;
        for (int i = 2; i <= n; i++)
            res = res.multiply(BigInteger.valueOf(i));
        return res;
    }
}
