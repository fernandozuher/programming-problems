// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.IntStream;

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

int beautifulDays(int startDay, int endDay, int divisor) {
    return (int) IntStream.range(startDay, endDay + 1).filter(day -> isDayBeautiful(day, divisor)).count();
}

boolean isDayBeautiful(int day, int divisor) {
    return Math.abs(day - reverseNumber(day)) % divisor == 0;
}

int reverseNumber(int number) {
    return Integer.parseInt(new StringBuilder(String.valueOf(number)).reverse().toString());
}
