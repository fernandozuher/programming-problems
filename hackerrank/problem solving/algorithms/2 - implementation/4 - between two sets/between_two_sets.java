// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] a = readNumbers();
    int[] b = readNumbers();
    IO.println(betweenTwoSets(a, b));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int betweenTwoSets(int[] a, int[] b) {
    int lcmOfA = reduce(a, this::lcm);
    int gcdOfB = reduce(b, this::gcd);
    return (int) IntStream.iterate(lcmOfA, i -> i <= gcdOfB, i -> i + lcmOfA)
            .filter(i -> gcdOfB % i == 0)
            .count();
}

int reduce(int[] arr, IntBinaryOperator func) {
    return Arrays.stream(arr).reduce(func).orElse(0);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
