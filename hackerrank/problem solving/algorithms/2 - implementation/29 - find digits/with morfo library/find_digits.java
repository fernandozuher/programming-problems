// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++)
        IO.println(findDigits(Reader.read(Integer::parseInt)));
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
int findDigits(int num) {
    return (int) String.valueOf(num).chars().map(c -> c - '0').filter(d -> d != 0 && num % d == 0).count();
}
