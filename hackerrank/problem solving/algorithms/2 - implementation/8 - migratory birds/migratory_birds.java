// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// Java 25

void main() {
    Map<Integer, Integer> birdsToCounts = readInput();
    IO.println(findMostSpottedBird(birdsToCounts));
}

// n: length of input
// T: O(n)
// S: O(n) extra space
Map<Integer, Integer> readInput() {
    IO.readln();
    Map<Integer, Integer> freqMap = new HashMap<>();
    Stream.of(IO.readln().split(" "))
            .map(Integer::parseInt)
            .forEach(x -> freqMap.put(x, freqMap.getOrDefault(x, 0) + 1));
    return freqMap;
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
int findMostSpottedBird(Map<Integer, Integer> birdsToCounts) {
    int resID = 0, resCount = 0;
    for (var x : birdsToCounts.entrySet())
        if (x.getValue() > resCount || (x.getValue() == resCount && x.getKey() < resID)) {
            resID = x.getKey();
            resCount = x.getValue();
        }
    return resID;
}
