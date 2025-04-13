// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.*;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            LinkedList<Integer> l = readList(scan);
            removeDuplicates(l);
            display(l);
        }
    }

    private static LinkedList<Integer> readList(Scanner scan) {
        int n = scan.nextInt();
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).collect(Collectors.toCollection(LinkedList::new));
    }

    private static void removeDuplicates(LinkedList<Integer> l) {
        HashSet<Integer> seen = new HashSet<>();
        l.removeIf(x -> !seen.add(x));
    }

    private static void display(LinkedList<Integer> l) {
        for (int x : l)
            System.out.print(x + " ");
    }
}
