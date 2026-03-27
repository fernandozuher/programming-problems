// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(minDeletionsToEqualize(readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
int minDeletionsToEqualize(int[] arr) {
    return arr.length - Collections.max(counter(arr).values());
}

HashMap<Integer, Integer> counter(int[] arr) {
    var freqMap = new HashMap<Integer, Integer>();
    for (int x : arr)
        freqMap.merge(x, 1, Integer::sum);
    return freqMap;
}
