// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int nWidths = scan.nextInt();
        int nPoints = scan.nextInt();
        scan.nextLine();
        int[] widths = readNumbers(scan, nWidths);

        for (int i = 0; i < nPoints; i++)
            IO.println(maxAffordableWidthVehicleInRange(widths, readNumbers(scan, 2)));
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int maxAffordableWidthVehicleInRange(int[] widths, int[] point) {
        return Arrays.stream(widths, point[0], point[1] + 1).min().getAsInt();
    }
}
