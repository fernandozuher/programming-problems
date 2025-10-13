// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        int beautifulDifference = scan.nextInt();
        scan.nextLine();
        List<Integer> arr = readNumbers(scan, n);
        IO.println(findBeautifulTriplets(arr, beautifulDifference));
    }

    private static List<Integer> readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).mapToObj(_ -> scan.nextInt()).toList();
    }

    private static int findBeautifulTriplets(List<Integer> arr, int beautifulDifference) {
        var values = new HashSet<>(arr);
        return (int) arr.stream()
                .filter(x -> values.contains(x + beautifulDifference) && values.contains(x + 2 * beautifulDifference))
                .count();
    }
}