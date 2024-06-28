// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// From Java 16

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        Collections.sort(array);
        System.out.println(divisibleSumPairs(array, k));
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static int divisibleSumPairs(final List<Integer> array, final int k) {
            int nDivisibleSumPairs = 0;
            for (int i = 0, n = array.size() - 1; i < n; ++i)
                for (int j = i + 1, n2 = array.size(); j < n2; ++j)
                    if (array.get(i) <= array.get(j) && (array.get(i) + array.get(j)) % k == 0)
                        ++nDivisibleSumPairs;
            return nDivisibleSumPairs;
        }
}
