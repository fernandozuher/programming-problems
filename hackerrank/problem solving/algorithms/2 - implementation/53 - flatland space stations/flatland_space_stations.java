// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// Java 25

void main() {
    int nCities = readNumbers()[0];
    int lastCity = nCities - 1;
    int[] stations = readNumbers();
    Arrays.sort(stations);
    IO.println(maxDistanceFromSpaceStation(lastCity, stations));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int maxDistanceFromSpaceStation(int lastCity, int[] stations) {
    int maxDist = stations[0];

    for (int i = 1; i < stations.length; i++) {
        int gap = (stations[i] - stations[i - 1]) / 2;
        maxDist = Math.max(maxDist, gap);
    }

    return Math.max(maxDist, lastCity - stations[stations.length - 1]);
}
