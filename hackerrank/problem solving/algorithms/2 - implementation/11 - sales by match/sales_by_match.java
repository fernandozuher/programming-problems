// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    Map<Integer, Integer> sockCounts = counter();
    IO.println(sockMerchant(sockCounts));
}

Map<Integer, Integer> counter() {
    var counter = new HashMap<Integer, Integer>();
    Stream.of(IO.readln().split(" "))
            .map(Integer::parseInt)
            .forEach(x -> counter.merge(x, 1, Integer::sum));
    return counter;
}

// n: quantity of entries in sockCounts
// T: O(n)
// S: O(1) extra space
int sockMerchant(Map<Integer, Integer> sockCounts) {
    return sockCounts.values()
            .stream()
            .reduce(0, (pairs, count) -> pairs + count / 2);
}
