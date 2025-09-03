// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int nRotation = scan.nextInt();
            int nQueries = scan.nextInt();
            int[] arr = readNumbers(scan, n);
            int[] queries = readNumbers(scan, nQueries);
            printQueries(arr, queries, nRotation);
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static void printQueries(int[] arr, int[] queries, int nRotation) {
        int n = arr.length;
        int r = nRotation % n;
        for (var q : queries) {
            int idx = (q + n - r) % n;
            System.out.println(arr[idx]);
        }
    }
}
