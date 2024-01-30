// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> testCases = readLines(n);

        var obj = new UtopianTree(testCases);
        obj.treesHeights().forEach(System.out::println);
    }

        private static List<Integer> readLines(final int n) {
            return IntStream.range(0, n)
                   .mapToObj(i -> scan.nextInt())
                   .collect(toList());
        }
}

    class UtopianTree {
        private List<Integer> testCases;
        private List<Integer> heights;

        public UtopianTree(final List<Integer> testCases) {
            this.testCases = testCases;
            heights = Arrays.asList(new Integer[testCases.size()]);
            calculateTreesHeights();
        }

            private void calculateTreesHeights() {
                for (int i = 0, n = heights.size(); i < n; ++i)
                    heights.set(i, calculateHeight(testCases.get(i)));
            }

                private int calculateHeight(final int cycles) {
                    int height = 1;
                    for (int cycle = 1; cycle <= cycles; ++cycle)
                        height = isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
                    return height;
                }

                    private boolean isCycleHappeningDuringSpring(final int cycle) {
                        return (cycle & 1) == 1;
                    }

        public List<Integer> treesHeights() {
            return heights;
        }
    }
