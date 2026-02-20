// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] chocolateSquares = readNumbers();
    int[] dayMonth = readNumbers();
    IO.println(birthday(chocolateSquares, dayMonth));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
int birthday(int[] chocolateSquares, int[] dayMonth) {
    int day = dayMonth[0];
    int month = dayMonth[1];
    if (month > chocolateSquares.length) return 0;

    int sum = Arrays.stream(chocolateSquares, 0, month).sum();
    int count = sum == day ? 1 : 0;

    for (int i = month; i < chocolateSquares.length; i++) {
        sum += chocolateSquares[i] - chocolateSquares[i - month];
        if (sum == day) count++;
    }

    return count;
}
