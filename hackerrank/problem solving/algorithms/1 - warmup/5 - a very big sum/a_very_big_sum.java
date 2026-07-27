// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    long[] arr = readNums();
    IO.println(aVeryBigSum(arr));
}

long[] readNums() {
    return Arrays.stream(IO.readln().split(" ")).mapToLong(Long::parseLong).toArray();
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long aVeryBigSum(long[] arr) {
    return Arrays.stream(arr).sum();
}
