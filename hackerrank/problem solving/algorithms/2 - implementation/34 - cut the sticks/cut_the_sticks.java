// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] arr = readNumbers();
    Arrays.sort(arr);
    cutTheSticks(arr).forEach(IO::println);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
List<Integer> cutTheSticks(int[] arr) {
    List<Integer> res = new ArrayList<>();
    int slow = 0, n = arr.length;

    for (int fast = 0; fast < n; fast++) {
        if (arr[slow] == arr[fast]) continue;
        res.add(n - slow);
        slow = fast;
    }

    res.add(n - slow);
    return res;
}
