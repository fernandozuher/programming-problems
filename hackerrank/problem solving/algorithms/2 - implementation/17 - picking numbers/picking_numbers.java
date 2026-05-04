// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    var freqMap = counter(readNumbers());
    IO.println(pickingNumbers(freqMap));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr
// k: length of freqMap
// k <= n
// T: O(n)
// S: O(k) extra space
Map<Integer, Integer> counter(int[] arr) {
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
