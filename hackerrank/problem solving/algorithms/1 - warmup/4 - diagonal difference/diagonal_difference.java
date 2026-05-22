// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// Java 25

void main() {
    int n = Integer.parseInt(IO.readln());
    IO.println(diagonalDifference(n));
}

// T: O(n^2)
// S: O(n) extra space
int diagonalDifference(int n) {
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        int[] arr = readNumbers();
        primarySum += arr[i];
        secondarySum += arr[n - i - 1];
    }

    return Math.abs(primarySum - secondarySum);
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}
