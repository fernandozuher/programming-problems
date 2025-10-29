// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;

void main() {
    IO.readln();
    Map<Integer, Integer> sockCounts = readNumbersIntoMap();
    IO.println(sockMerchant(sockCounts));
}

Map<Integer, Integer> readNumbersIntoMap() {
    var counter = new HashMap<Integer, Integer>();
    for (int x : Stream.of(IO.readln().split(" ")).map(Integer::parseInt).toList())
        counter.merge(x, 1, Integer::sum);
    return counter;
}

int sockMerchant(Map<Integer, Integer> sockCounts) {
    return sockCounts.values().stream().reduce(0, (pairs, count) -> pairs + count / 2);
}
