// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        Map<String, Integer> input = readInput(n);

        n = scan.nextInt();
        scan.nextLine();
        List<Integer> result = readQueriesAndCountMatches(input, n);

        result.forEach(System.out::println);
    }

        public static Map<String, Integer> readInput(int n) {
            var input = new HashMap<String, Integer>();
            while (n-- > 0) {
                String x = scan.nextLine();
                input.put(x, input.getOrDefault(x, 0) + 1);
            }
            return input;
        }

        public static List<Integer> readQueriesAndCountMatches(Map<String, Integer> input, int n) {
            var result = Arrays.asList(new Integer[n]);
            for (int i = 0; i < n; ++i) {
                String query = scan.nextLine();
                int count = input.containsKey(query) ? input.get(query) : 0;
                result.set(i, count);
            }
            return result;
        }
}
