// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(equalizeArray(readNumbers()));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int equalizeArray(int[] arr) {
    int maxCount = Collections.max(counter(arr).values());
    return arr.length - maxCount;
}

HashMap<Integer, Integer> counter(int[] arr) {
    var counter = new HashMap<Integer, Integer>();
    for (int x : arr)
        counter.merge(x, 1, Integer::sum);
    return counter;
}
