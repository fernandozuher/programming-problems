// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
// Java 25

void main() {
    int n = Integer.parseInt(IO.readln());
    String[] strings = readLines(n);
    Map<String, Integer> stringsToCounts = counter(strings);

    n = Integer.parseInt(IO.readln());
    String[] queries = readLines(n);

    for (var x : countsFrom(stringsToCounts, queries))
        IO.println(x);
}

String[] readLines(int n) {
    return IntStream.range(0, n).mapToObj(_ -> IO.readln()).toArray(String[]::new);
}

Map<String, Integer> counter(String[] arr) {
    var freqMap = new HashMap<String, Integer>();
    for (var x : arr)
        freqMap.put(x, freqMap.getOrDefault(x, 0) + 1);
    return freqMap;
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
int[] countsFrom(Map<String, Integer> freqMap, String[] queries) {
    return Arrays.stream(queries).mapToInt(q -> freqMap.getOrDefault(q, 0)).toArray();
}
