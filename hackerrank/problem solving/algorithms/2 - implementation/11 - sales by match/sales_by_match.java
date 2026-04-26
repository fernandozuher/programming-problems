// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    Map<Integer, Integer> socksToCounts = counter(readNumbers());
    IO.println(sockMerchant(socksToCounts));
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
Map<Integer, Integer> counter(int[] arr) {
    var freqMap = new HashMap<Integer, Integer>();
    for (var x : arr)
        freqMap.merge(x, 1, Integer::sum);
    return freqMap;
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
int sockMerchant(Map<Integer, Integer> socksToCounts) {
    return socksToCounts.values().stream().mapToInt(x -> x / 2).sum();
}
