// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        int rotateBy = scan.nextInt();
        List<Integer> array = readIntArray(n);

        if (rotateBy > n - 1)
            rotateBy %= n;

        Collections.rotate(array, -rotateBy);
        array.forEach(x -> System.out.print(x + " "));
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList());
        }
}
