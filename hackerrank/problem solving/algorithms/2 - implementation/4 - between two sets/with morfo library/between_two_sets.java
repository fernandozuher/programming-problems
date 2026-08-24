// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.math.Gcd;
import morfo.math.Lcm;

void main() {
    Reader.skipInputLn();
    int[] a = Reader.readLnInts();
    int[] b = Reader.readLnInts();
    IO.println(betweenTwoSets(a, b));
}

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
int betweenTwoSets(int[] a, int[] b) {
    int lcmOfA = Lcm.ofInts(a);
    int gcdOfB = Gcd.ofInts(b);
    return (int) IntStream.iterate(lcmOfA, i -> i <= gcdOfB, i -> i + lcmOfA)
            .filter(i -> gcdOfB % i == 0)
            .count();
}
