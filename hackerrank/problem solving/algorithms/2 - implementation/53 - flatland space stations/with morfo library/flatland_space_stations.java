// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int nCities = Reader.readLnInts()[0];
    int lastCity = nCities - 1;
    int[] stations = Reader.readLnInts();
    Arrays.sort(stations);
    IO.println(maxDistanceFromSpaceStation(lastCity, stations));
}

// n: length of stations
// T: O(n)
// S: O(1) extra space
int maxDistanceFromSpaceStation(int lastCity, int[] stations) {
    int maxDist = stations[0];
    int n = stations.length;

    for (int i = 1; i < n; i++) {
        int gap = (stations[i] - stations[i - 1]) / 2;
        maxDist = Math.max(maxDist, gap);
    }

    return Math.max(maxDist, lastCity - stations[n - 1]);
}
