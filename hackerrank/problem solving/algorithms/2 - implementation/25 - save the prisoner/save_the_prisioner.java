// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();

            IntStream.range(0, n).map(_ -> {
                int prisoners = scan.nextInt();
                int sweets = scan.nextInt();
                int startChair = scan.nextInt();
                return saveThePrisoner(prisoners, sweets, startChair);
            })
            .forEach(System.out::println);
        }
    }

    private static int saveThePrisoner(int prisoners, int sweets, int startChair) {
        return ((startChair - 1 + sweets - 1) % prisoners) + 1;
    }
}
