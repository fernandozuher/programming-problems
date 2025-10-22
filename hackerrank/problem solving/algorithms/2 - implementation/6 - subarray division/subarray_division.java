// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.Stream;

class Solution {
    void main() {
        IO.readln();
        int[] chocolateSquares = readNumbers();
        int[] dayMonth = readNumbers();
        IO.println(birthday(chocolateSquares, dayMonth));
    }

    private static int[] readNumbers() {
        return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int birthday(int[] chocolateSquares, int[] dayMonth) {
        int day = dayMonth[0];
        int month = dayMonth[1];
        if (month > chocolateSquares.length) return 0;

        int sum = Arrays.stream(chocolateSquares, 0, month).sum();
        int waysBarCanBeDivided = sum == day ? 1 : 0;

        for (int i = month; i < chocolateSquares.length; i++) {
            sum += chocolateSquares[i] - chocolateSquares[i - month];
            if (sum == day) waysBarCanBeDivided++;
        }

        return waysBarCanBeDivided;
    }
}
