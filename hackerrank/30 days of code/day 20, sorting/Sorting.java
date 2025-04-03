// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true
// Java 21

import java.util.*;
import static java.util.stream.Collectors.toList;
import java.util.stream.*;

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        List<Integer> numbers = readInput();
        int nSwaps = bubbleSort(numbers);
        System.out.format("Array is sorted in %d swaps.", nSwaps);
        System.out.format("\nFirst Element: %d", numbers.getFirst());
        System.out.format("\nLast Element: %d", numbers.getLast());
    }

    private static List<Integer> readInput() {
        int n = scan.nextInt();
        scan.nextLine(); // Skip new line character
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).collect(toList());
    }

    private static int bubbleSort(List<Integer> l) {
        int totalSwaps = 0;
        for (int end = l.size(); end > 0; ) {
            Pair pair = sortSlice(l, end);
            totalSwaps += pair.nSwaps;
            end = pair.newEnd;
        }
        return totalSwaps;
    }

    private static Pair sortSlice(List<Integer> l, int end) {
        int nSwaps = 0, newEnd = 0;
        --end; // Decrease end to avoid out of range error
        for (int i = 0; i < end; i++)
            if (l.get(i) > l.get(i + 1)) {
                Collections.swap(l, i, i + 1);
                ++nSwaps;
                newEnd = i + 1;
            }
        return new Pair(nSwaps, newEnd);
    }

    private record Pair(int nSwaps, int newEnd) {}
}
