// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// Java 22

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            scan.nextLine();
            IntStream.range(0, n)
                    .mapToObj(_ -> findNearestCatOrNot(readNumbers(scan, 3)))
                    .forEach(System.out::println);
        }
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static String findNearestCatOrNot(int[] positions) {
        int catA = positions[0];
        int catB = positions[1];
        int mouse = positions[2];
        int catAFromMouse = Math.abs(catA - mouse);
        int catBFromMouse = Math.abs(catB - mouse);

        if (catAFromMouse < catBFromMouse) return "Cat A";
        if (catAFromMouse > catBFromMouse) return "Cat B";
        return "Mouse C";
    }
}
