// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

import java.util.Scanner;

public class MoreExceptions {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Calculator calc = new Calculator();

        for (int nTests = scan.nextInt(); nTests-- > 0;) {
            int n = scan.nextInt();
            int p = scan.nextInt();

            try {
                System.out.println(calc.power(n, p));
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

    class Calculator {
        public int power(int n, int p) throws Exception {
            if (n < 0 || p < 0)
                throw new Exception("n and p should be non-negative");
            return (int) Math.pow(n, p);
        }
    }
