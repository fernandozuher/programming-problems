// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

import java.util.*;
import java.util.stream.IntStream;
import static java.util.stream.Collectors.toCollection;

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();
        List<Integer> list = initializeList(n);
        displayList(list);
    }

    private static LinkedList<Integer> initializeList(int n) {
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).collect(toCollection(LinkedList::new));
    }

    private static void displayList(List<Integer> list) {
        list.forEach(x -> System.out.print(x + " "));
    }
}
