// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            scan.nextLine(); // size not used
            List<Integer> array = Arrays.stream(scan.nextLine().split(" ")).map(Integer::parseInt).toList();
            var difference = new Difference(array);
            difference.computeDifference();
            System.out.println(difference.maximumDifference);
        }
    }
}

class Difference {
    private final List<Integer> elements;
    public int maximumDifference;

    Difference(List<Integer> elements) {
        this.elements = elements;
    }

    void computeDifference() {
        maximumDifference = Collections.max(elements) - Collections.min(elements);
    }
}
    