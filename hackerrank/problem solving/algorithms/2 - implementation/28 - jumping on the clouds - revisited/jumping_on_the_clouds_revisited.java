// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int jumpLength = scan.nextInt();
            int[] arr = readNumbers(scan, n);
            System.out.println(jumpingOnTheClouds(arr, jumpLength));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }


    private static int jumpingOnTheClouds(int[] clouds, int jumpLength) {
        int energy = 100;
        int cloudIndex = 0;

        do {
            energy -= clouds[cloudIndex] == 0 ? 1 : 3;
            cloudIndex = (cloudIndex + jumpLength) % clouds.length;
        } while (cloudIndex != 0);

        return energy;
    }
}
