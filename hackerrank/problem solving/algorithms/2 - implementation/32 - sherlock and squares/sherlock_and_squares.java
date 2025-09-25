// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        for (int i = 0; i < n; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            IO.println(squares(a, b));
        }
    }

    private static int squares(int startNum, int endNum) {
        int maxSquare = (int) Math.floor(Math.sqrt(endNum));
        int minSquare = (int) Math.ceil(Math.sqrt(startNum));
        return maxSquare - minSquare + 1;
    }
}
