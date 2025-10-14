// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] arr = readNumbers(scan, n);
        IO.println(minDistance(arr));
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int minDistance(int[] arr) {
        var lastSeen = new HashMap<Integer, Integer>();
        int minDist = -1;

        for (int i = 0; i < arr.length; i++) {
            int x = arr[i];

            if (lastSeen.containsKey(x)) {
                int dist = i - lastSeen.get(x);
                if (minDist == -1 || dist < minDist) {
                    minDist = dist;
                    if (minDist == 1) return 1;
                }
            }
            lastSeen.put(x, i);
        }

        return minDist;
    }
}
