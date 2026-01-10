// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(pickingNumbers(counter()));
}

Map<Integer, Integer> counter() {
    var arr = Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    Map<Integer, Integer> frequency = new HashMap<>();
    for (int num : arr)
        frequency.put(num, frequency.getOrDefault(num, 0) + 1);
    return frequency;
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
int pickingNumbers(Map<Integer, Integer> frequency) {
    int maxLen = 0;
    for (var num : frequency.keySet()) {
        int current = frequency.get(num) + frequency.getOrDefault(num + 1, 0);
        maxLen = Math.max(maxLen, current);
    }
    return maxLen;
}
