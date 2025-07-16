// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            scan.nextLine();
            System.out.println(pickingNumbers(readNumbers(scan)));
        }
    }

    private static int[] readNumbers(Scanner scan) {
        return Arrays.stream(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int pickingNumbers(int[] numbers) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int num : numbers)
            counter.put(num, counter.getOrDefault(num, 0) + 1);

        int maxLen = 0;
        for (var num : counter.keySet()) {
            int current = counter.get(num) + counter.getOrDefault(num + 1, 0);
            maxLen = Math.max(maxLen, current);
        }

        return maxLen;
    }
}
