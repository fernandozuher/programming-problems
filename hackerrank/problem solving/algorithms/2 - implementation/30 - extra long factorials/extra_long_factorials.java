// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true
// Java 25

void main() {
    int n = Integer.parseInt(IO.readln());
    IO.println(factorial(n));
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
BigInteger factorial(int n) {
    return IntStream.range(1, n + 1).mapToObj(BigInteger::valueOf).reduce(BigInteger::multiply).orElse(BigInteger.ONE);
}
