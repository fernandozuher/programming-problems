// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    IO.println(sumStdin());
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
int sumStdin() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).sum();
}
