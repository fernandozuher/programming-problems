// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    var arr = new ArrayList<>(Arrays.stream(IO.readln().split(" ")).map(Integer::parseInt).toList());
    Collections.reverse(arr);
    for (var x : arr)
        System.out.printf("%d ", x);
}
