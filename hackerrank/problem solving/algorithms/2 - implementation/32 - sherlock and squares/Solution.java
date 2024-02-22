// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.lang.Math;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        List<Integer> output = Arrays.asList(new Integer[n]);

        for (int i = 0; i < n; ++i) {
            int begin = scan.nextInt();
            int end = scan.nextInt();
            var obj = new SherlockAndSquares(begin, end);
            output.set(i, obj.squareIntegers());
        }

        output.forEach(System.out::println);
    }
}

    class SherlockAndSquares {
        private int begin;
        private int end;
        private int nSquareIntegers;

        public SherlockAndSquares(final int begin, final int end) {
            this.begin = begin;
            this.end = end;
            nSquareIntegers = 0;
            calculateQuantityOfSquareIntegersInRange();
        }

            private void calculateQuantityOfSquareIntegersInRange() {
                for (int number = findFirstSquareInteger(); isPowerOf2LessThanOrEqualToLimit(number); ++number)
                    ++nSquareIntegers;
            }

                private int findFirstSquareInteger() {
                    double squareRoot = Math.sqrt(begin);
                    int integerPart = (int) Math.floor(squareRoot);
                    return squareRoot == integerPart ? integerPart : integerPart + 1;
                }

                private boolean isPowerOf2LessThanOrEqualToLimit(final int x) {
                    return Math.pow(x, 2) <= end;
                }

        public int squareIntegers() {
            return nSquareIntegers;
        }
    }
