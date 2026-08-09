// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int startDay = Reader.read(Integer::parseInt);
    int endDay = Reader.read(Integer::parseInt);
    int divisor = Reader.read(Integer::parseInt);
    IO.println(beautifulDays(startDay, endDay, divisor));
}

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
int beautifulDays(int startDay, int endDay, int divisor) {
    return (int) IntStream.range(startDay, endDay + 1).filter(day -> isBeautifulDay(day, divisor)).count();
}

boolean isBeautifulDay(int day, int divisor) {
    return (day - reverseNumber(day)) % divisor == 0;
}

int reverseNumber(int number) {
    return Integer.parseInt(new StringBuilder(String.valueOf(number)).reverse().toString());
}
