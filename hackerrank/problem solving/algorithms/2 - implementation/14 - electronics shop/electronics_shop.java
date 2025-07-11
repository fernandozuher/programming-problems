// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int budget = scan.nextInt();
            int nKeyboards = scan.nextInt();
            int nUsbDrives = scan.nextInt();
            int[] keyboards = IntStream.of(readNumbers(scan, nKeyboards)).distinct().toArray();
            int[] usbDrives = IntStream.of(readNumbers(scan, nUsbDrives)).distinct().toArray();
            Arrays.sort(keyboards);
            Arrays.sort(usbDrives);
            System.out.println(calculateMoneySpent(keyboards, usbDrives, budget));
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int calculateMoneySpent(int[] keyboards, int[] usbDrives, int budget) {
        int maxSpent = -1, i = 0, j = usbDrives.length - 1;

        while (i < keyboards.length && j >= 0) {
            if (keyboards[i] >= budget) break;

            int sum = keyboards[i] + usbDrives[j];
            if (sum > budget) j--;
            else if (sum == budget) return budget;
            else {
                if (sum > maxSpent) maxSpent = sum;
                i++;
            }
        }

        return maxSpent;
    }
}
