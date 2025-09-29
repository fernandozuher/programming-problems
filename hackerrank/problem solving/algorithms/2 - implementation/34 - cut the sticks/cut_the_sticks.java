// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true
// Java 25

import java.util.*;
import java.lang.IO;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        int[] arr = readNumbers(scan, n);
        Arrays.sort(arr);
        cutTheSticks(arr).forEach(IO::println);
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private List<Integer> cutTheSticks(int[] arr) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0, n = arr.length; i < n; ) {
            res.add(n - i);
            for (int shortest = arr[i]; i < n && arr[i] == shortest; i++);
        }
        return res;
    }
}
