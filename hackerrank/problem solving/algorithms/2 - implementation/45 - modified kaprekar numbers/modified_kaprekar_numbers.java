// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// Java 25

void main() {
    int lower = readNumber();
    int upper = readNumber();
    boolean validRange = false;

    for (int num = lower; num <= upper; num++)
        if (isNumberKaprekar(num)) {
            IO.print(num + " ");
            validRange = true;
        }

    if (!validRange) IO.println("INVALID RANGE");
}

int readNumber() {
    return Integer.parseInt(IO.readln());
}

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
boolean isNumberKaprekar(int n) {
    long squareNumber = (long) Math.pow(n, 2);
    long divisor = (long) Math.pow(10, numberDigits(n));
    long leftNumber = squareNumber / divisor;
    long rightNumber = squareNumber % divisor;
    return n == leftNumber + rightNumber;
}

int numberDigits(long n) {
    return (int) Math.log10(n) + 1;
}
