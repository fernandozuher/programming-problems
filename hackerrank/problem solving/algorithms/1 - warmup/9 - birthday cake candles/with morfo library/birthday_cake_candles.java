// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    int[] candles = Reader.readLnInts();
    IO.println(birthdayCakeCandles(candles));
}

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
int birthdayCakeCandles(int[] candles) {
    int max = Arrays.stream(candles).max().orElse(0);
    return (int) Arrays.stream(candles).filter(x -> x == max).count();
}
