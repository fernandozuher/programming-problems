// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int[] arr = readNumbers(scan, n);
            int[] res = sequenceEquation(arr);
            for (int val : res) {
                System.out.println(val);
            }
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int[] sequenceEquation(int[] arr) {
        int[] valuesToIndex = new int[arr.length];
        int i = 0;
        for (int val : arr) {
            valuesToIndex[val - 1] = i++;
        }

        int[] res = new int[arr.length];
        i = 0;
        for (int val : valuesToIndex) {
            res[i++] = valuesToIndex[val] + 1;
        }

        return res;
    }
}
