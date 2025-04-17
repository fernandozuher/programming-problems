// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            int nTests = scan.nextInt();
            processPrimeTests(scan, nTests);
        }
    }

    private static void processPrimeTests(Scanner scanner, int nTests) {
        while (nTests-- > 0) {
            int n = scanner.nextInt();
            System.out.println(isPrime(n) ? "Prime" : "Not prime");
        }
    }

    private static boolean isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int divisor = 3, limit = (int) Math.sqrt(n); divisor <= limit; divisor += 2)
            if (n % divisor == 0)
                return false;
        return true;
    }
}
