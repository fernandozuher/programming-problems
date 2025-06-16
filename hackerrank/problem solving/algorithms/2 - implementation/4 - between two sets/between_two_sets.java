// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n1 = scan.nextInt();
            int n2 = scan.nextInt();
            int[] numbersA = readNumbers(scan, n1);
            int[] numbersB = readNumbers(scan, n2);
            System.out.println(betweenTwoSets(numbersA, numbersB));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int betweenTwoSets(int[] a, int[] b) {
        int lcmOfA = lcmArray(a);
        int gcdOfB = gcdArray(b);

        int count = 0;
        for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
            if (gcdOfB % i == 0) count++;
        return count;
    }

    private static int lcmArray(int[] numbers) {
        return Arrays.stream(numbers).skip(1).reduce(numbers[0], Solution::lcm);
    }

    private static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    private static int gcdArray(int[] numbers) {
        return Arrays.stream(numbers).skip(1).reduce(numbers[0], Solution::gcd);
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
