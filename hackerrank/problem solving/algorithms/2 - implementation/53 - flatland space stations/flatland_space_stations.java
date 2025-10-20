// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int nCities = scan.nextInt();
        int nStations = scan.nextInt();
        int[] stations = readNumbers(scan, nStations);
        Arrays.sort(stations);
        IO.println(maxDistanceFromSpaceStation(nCities, stations));
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static int maxDistanceFromSpaceStation(int nCities, int[] stations) {
        int maxDist = stations[0];

        for (int i = 1; i < stations.length; i++) {
            int gap = (stations[i] - stations[i - 1]) / 2;
            maxDist = Math.max(maxDist, gap);
        }

        int lastCity = nCities - 1;
        return Math.max(maxDist, lastCity - stations[stations.length - 1]);
    }
}
