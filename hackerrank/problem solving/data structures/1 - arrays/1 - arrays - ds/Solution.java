// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList());
        array = reverseArray(array);

        for (var x : array)
            System.out.printf("%d ", x);
    }

        public static List<Integer> reverseArray(List<Integer> array) {
            Collections.reverse(array);
            return array;
        }
}
