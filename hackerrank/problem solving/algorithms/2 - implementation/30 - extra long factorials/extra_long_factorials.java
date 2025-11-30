// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true
// Java 25

void main() {
    int n = Integer.parseInt(IO.readln());
    IO.println(factorial(n));
}

BigInteger factorial(int n) {
    return IntStream.range(1, n + 1).mapToObj(BigInteger::valueOf).reduce(BigInteger.ONE, BigInteger::multiply);
}
