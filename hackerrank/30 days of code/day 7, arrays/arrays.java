// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        final int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = Arrays.stream(scan.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        ListIterator iterator = array.listIterator(array.size());

        while (iterator.hasPrevious())
            System.out.print(iterator.previous() + " ");
    }
}
