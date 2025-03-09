// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            var binary = Integer.toBinaryString(n);
            System.out.println(findMaxLengthOfOnes(binary));
        }
    }

    public static int findMaxLengthOfOnes(String binary) {
        return Arrays.stream(binary.split("0")).mapToInt(String::length).max().orElse(0);
    }
}
