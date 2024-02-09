// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String args[]) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        var nNumberDivisors = Arrays.asList(new Integer[n]);

        for (int i = 0; i < n; ++i) {
            int number = scan.nextInt();
            var obj = new FindDigits(number);
            nNumberDivisors.set(i, obj.divisors());
        }

        nNumberDivisors.forEach(System.out::println);
    }
}

    class FindDigits {
        private int number;
        private int nDivisors;

        public FindDigits(final int number) {
            this.number = number;
            nDivisors = 0;
            findNumberDivisorsQuantity();
        }

            private void findNumberDivisorsQuantity() {
                for (int currentNumber = number; currentNumber != 0; currentNumber = removeLastDigitOfNumber(currentNumber)) {
                    int divisor = getLastDigitOfNumber(currentNumber);
                    if (isNumberEvenlyDividedByDivisor(divisor))
                        ++nDivisors;
                }
            }

                private int getLastDigitOfNumber(final int number) {
                    return number % 10;
                }

                private boolean isNumberEvenlyDividedByDivisor(final int divisor) {
                    return divisor != 0 && number % divisor == 0;
                }

                private int removeLastDigitOfNumber(final int number) {
                    return number / 10;
                }

        public int divisors() {
            return nDivisors;
        }
    }
