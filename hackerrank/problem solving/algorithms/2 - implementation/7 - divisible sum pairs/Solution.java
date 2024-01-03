// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

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

        List<Integer> array = readIntArray();

        Collections.sort(array);

        var obj = new SubarrayDivision(array, k);
        System.out.println(obj.nDivisibleSumPairs());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class SubarrayDivision {
        private List<Integer> array;
        private int k;
        private int nDivisible;

        public SubarrayDivision(final List<Integer> array, final int k) {
            this.array = array;
            this.k = k;
            nDivisible = 0;

            divisibleSumPairs();
        }

            private void divisibleSumPairs() {
                for (int i = 0, n2 = array.size() - 1; i < n2; ++i)
                    for (int j = i + 1, n = array.size(); j < n; ++j)
                        if (array.get(i) <= array.get(j) && (array.get(i) + array.get(j)) % k == 0)
                            ++nDivisible;
            }

        public int nDivisibleSumPairs() {
            return nDivisible;
        }
    }
