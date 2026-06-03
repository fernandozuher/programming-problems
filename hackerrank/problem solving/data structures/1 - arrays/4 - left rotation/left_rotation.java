// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true
// Java 25

void main() {
    var arr = readNumbers();
    int rotateBy = arr.get(1);
    arr = readNumbers();
    rotate(arr, rotateBy);
    arr.forEach(x -> IO.print(x + " "));
}

List<Integer> readNumbers() {
    return new ArrayList<>(Arrays.stream(IO.readln().split(" ")).map(Integer::parseInt).toList());
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void rotate(List<Integer> arr, int rotateBy) {
    if (rotateBy >= arr.size()) rotateBy %= arr.size();
    Collections.rotate(arr, -rotateBy);
}
