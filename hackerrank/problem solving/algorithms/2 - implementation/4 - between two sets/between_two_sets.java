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
    int lcmOfA = lcmArray(a);
    int gcdOfB = gcdArray(b);

    int count = 0;
    for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
        if (gcdOfB % i == 0) count++;
    return count;
}

int lcmArray(int[] arr) {
    return Arrays.stream(arr).reduce(this::lcm).getAsInt();
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int gcdArray(int[] arr) {
    return Arrays.stream(arr).reduce(this::gcd).getAsInt();
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
