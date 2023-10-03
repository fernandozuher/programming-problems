// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

import java.util.Scanner;

public class Interfaces {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        Calculator calc = new Calculator();
        System.out.println("I implemented: AdvancedArithmetic\n" + calc.divisorSum(n));
    }
}

    interface AdvancedArithmetic {
        public int divisorSum(final int n);
    }

        class Calculator implements AdvancedArithmetic {
            @Override
            public int divisorSum(int n) {
                int sum = 0;
                for (int i = 1; i <= n / 2; ++i)
                    if (n % i == 0)
                        sum += i;
                return sum + n;
            }
        }
