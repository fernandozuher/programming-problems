// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Solution {
    public static void main(String[] args) {
        final Scanner scan = new Scanner(System.in);
        final int n = scan.nextInt(); // Not used
        scan.nextLine(); // Just to drop new line

        final List<Integer> array = Arrays.stream(scan.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        final Difference difference = new Difference(array);
        difference.computeDifference();
        System.out.println(difference.maximumDifference);
    }
}

    class Difference {
        private List<Integer> elements;
        public int maximumDifference;

        Difference(List<Integer> elements) {
            this.elements = elements;
        }

        void computeDifference() {
            Collections.sort(elements);
            maximumDifference = elements.get(elements.size() - 1) - elements.get(0);
        }
    }
