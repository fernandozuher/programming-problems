// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            Calculator calc = new Calculator();
            System.out.println("I implemented: AdvancedArithmetic\n" + calc.divisorSum(n));
        }
    }
}

interface AdvancedArithmetic {
    int divisorSum(int n);
}

class Calculator implements AdvancedArithmetic {
    @Override
    public int divisorSum(final int n) {
        int sum = 0;
        for (int i = 1; i <= n / 2; ++i)
            if (isDivisibleBy(n, i))
                sum += i;
        return sum + n;
    }

    private static boolean isDivisibleBy(int a, int b) {
        return a % b == 0;
    }
}
