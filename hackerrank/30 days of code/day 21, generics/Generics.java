// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main() {
        List<Integer> numbers = readInput(Integer.class);
        List<String> strings = readInput(String.class);
        printList(numbers);
        printList(strings);
    }

    private static <T> List<T> readInput(Class<T> type) {
        Objects.requireNonNull(type, "Type cannot be null");
        int n = scan.nextInt();
        scan.nextLine(); // Skip new line character
        return IntStream.range(0, n)
                .mapToObj(_ -> type == Integer.class ? (T) Integer.valueOf(scan.nextLine()) : (T) scan.nextLine())
                .toList();
    }

    private static <T> void printList(List<T> l) {
        l.forEach(System.out::println);
    }
}
