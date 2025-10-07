// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isfullscreen=true
// Java 25

import java.util.*;
import java.lang.IO;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        IO.println(equalizeArray(counter(scan, n), n));
    }

    private static HashMap<Integer, Integer> counter(Scanner scan, int n) {
        var counter = new HashMap<Integer, Integer>();
        while (n-- > 0)
            counter.merge(scan.nextInt(), 1, Integer::sum);
        return counter;
    }

    private static int equalizeArray(HashMap<Integer, Integer> counter, int n) {
        int maxCount = Collections.max(counter.values());
        return n - maxCount;
    }
}
