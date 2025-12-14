// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// Java 25

void main() {
    int lower = readNumbers()[0];
    int upper = readNumbers()[0];
    boolean validRange = false;

    for (int num = lower; num <= upper; num++)
        if (isNumberKaprekar(num)) {
            IO.print(num + " ");
            validRange = true;
        }

    if (!validRange) IO.println("INVALID RANGE");
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

boolean isNumberKaprekar(int n) {
    long squareNumber = (long) Math.pow(n, 2);
    long divisor = (long) Math.pow(10, numberDigits(n));
    long leftNumber = squareNumber / divisor;
    long rightNumber = squareNumber % divisor;
    return n == leftNumber + rightNumber;
}

int numberDigits(long n) {
    return String.valueOf(n).length();
}
