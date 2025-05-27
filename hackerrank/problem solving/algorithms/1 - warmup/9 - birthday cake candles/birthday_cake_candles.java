// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// Java 22

import java.util.Scanner;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int[] candles = readNumbers(scan, n);
            System.out.println(birthdayCakeCandles(candles));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int birthdayCakeCandles(int[] candles) {
        int max = IntStream.of(candles).max().getAsInt();
        return (int) IntStream.of(candles).filter(x -> x == max).count();
    }
}
