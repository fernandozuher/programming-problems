// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// Java 25

void main() {
    int[] arr = readNumbers();
    int startDay = arr[0];
    int endDay = arr[1];
    int divisor = arr[2];
    IO.println(beautifulDays(startDay, endDay, divisor));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int beautifulDays(int startDay, int endDay, int divisor) {
    return (int) IntStream.range(startDay, endDay + 1).filter(day -> isDayBeautiful(day, divisor)).count();
}

boolean isDayBeautiful(int day, int divisor) {
    return (day - reverseNumber(day)) % divisor == 0;
}

int reverseNumber(int number) {
    return Integer.parseInt(new StringBuilder(String.valueOf(number)).reverse().toString());
}
