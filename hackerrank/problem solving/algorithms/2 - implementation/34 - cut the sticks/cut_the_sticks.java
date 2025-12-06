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

List<Integer> cutTheSticks(int[] arr) {
    List<Integer> res = new ArrayList<>();
    for (int i = 0, n = arr.length; i < n; ) {
        res.add(n - i);
        for (int shortest = arr[i]; i < n && arr[i] == shortest; i++);
    }
    return res;
}
