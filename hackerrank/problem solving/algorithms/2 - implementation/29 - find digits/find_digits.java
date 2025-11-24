// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true
// Java 25

void main() {
    int n = readNumber();
    for (int i = 0; i < n; i++)
        IO.println(findDigits(readNumber()));
}

int readNumber() {
    return Integer.parseInt(IO.readln());
}

int findDigits(int n) {
    return (int) String.valueOf(n).chars().map(c -> c - '0').filter(d -> d != 0 && n % d == 0).count();
}
