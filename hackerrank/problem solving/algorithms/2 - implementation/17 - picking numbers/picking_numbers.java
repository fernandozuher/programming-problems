// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(pickingNumbers(counter()));
}

// n: length of initial input array of numbers
// T: O(n)
// S: O(n) extra space
Map<Integer, Integer> counter() {
    var arr = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    Map<Integer, Integer> freqMap = new HashMap<>();
    for (int num : arr)
        freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
    return freqMap;
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int pickingNumbers(Map<Integer, Integer> freqMap) {
    int maxLen = 0;
    for (var num : freqMap.keySet()) {
        int current = freqMap.get(num) + freqMap.getOrDefault(num + 1, 0);
        maxLen = Math.max(maxLen, current);
    }
    return maxLen;
}
