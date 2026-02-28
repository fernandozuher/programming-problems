// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    Map<Integer, Integer> socksToCounts = counter();
    IO.println(sockMerchant(socksToCounts));
}

// n: length of user input
// k: length of distinct numbers in user input
// T: O(n)
// S: O(n) extra space
Map<Integer, Integer> counter() {
    var freqMap = new HashMap<Integer, Integer>();
    Stream.of(IO.readln().split(" "))
            .map(Integer::parseInt)
            .forEach(x -> freqMap.merge(x, 1, Integer::sum));
    return freqMap;
}

// n: length of initial user input
// k: length of entries in socksToCounts
// k <= n
// T: O(k)
// S: O(1) extra space
int sockMerchant(Map<Integer, Integer> socksToCounts) {
    return socksToCounts.values().stream().mapToInt(x -> x / 2).sum();
}
