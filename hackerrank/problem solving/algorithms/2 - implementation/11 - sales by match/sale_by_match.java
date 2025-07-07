// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            Map<Integer, Integer> sockCounts = readNumbersIntoMap(scan, n);
            System.out.println(sockMerchant(sockCounts));
        }
    }

    private static Map<Integer, Integer> readNumbersIntoMap(Scanner scan, int n) {
        var numberCounts = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            int x = scan.nextInt();
            numberCounts.merge(x, 1, Integer::sum);
        }
        return numberCounts;
    }

    private static int sockMerchant(Map<Integer, Integer> sockCounts) {
        return sockCounts.values().stream().reduce(0, (pairs, count) -> pairs + count / 2);
    }
}
