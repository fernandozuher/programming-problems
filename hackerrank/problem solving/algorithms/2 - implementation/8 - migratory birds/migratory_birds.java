// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    Map<Integer, Integer> birdCounts = counter();
    IO.println(findMostSpottedBird(birdCounts));
}

Map<Integer, Integer> counter() {
    Map<Integer, Integer> numberCounts = new HashMap<>();
    Stream.of(IO.readln().split(" "))
            .map(Integer::parseInt)
            .forEach(x -> numberCounts.put(x, numberCounts.getOrDefault(x, 0) + 1));
    return numberCounts;
}

int findMostSpottedBird(Map<Integer, Integer> birdCounts) {
    return birdCounts.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();
}
