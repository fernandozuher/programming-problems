// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

class Solution {
    void main() {
        IO.readln();
        int[] peopleLoafCounts = readNumbers();
        int minLoaves = minLoavesToSatisfyRules(peopleLoafCounts);
        IO.println(minLoaves == -1 ? "NO" : minLoaves);
    }

    private static int[] readNumbers() {
        return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int minLoavesToSatisfyRules(int[] peopleLoafCounts) {
        int loavesGiven = 0;
        int counts = peopleLoafCounts[0];

        for (int i = 1; i < peopleLoafCounts.length; i++) {
            if (isOdd(counts)) {
                loavesGiven += 2;
                counts = peopleLoafCounts[i] + 1;
            } else {
                counts = peopleLoafCounts[i];
            }
        }

        if (isOdd(counts)) {
            return -1;
        }
        return loavesGiven;
    }

    private static boolean isOdd(int n) {
        return n % 2 == 1;
    }
}