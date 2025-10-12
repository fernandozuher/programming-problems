// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.Scanner;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int lower = scan.nextInt();
        int upper = scan.nextInt();
        boolean validRange = false;

        for (int number = lower; number <= upper; number++)
            if (isNumberKaprekar(number)) {
                IO.print(number + " ");
                validRange = true;
            }

        if (!validRange) IO.println("INVALID RANGE");
    }

    private static boolean isNumberKaprekar(int number) {
        long squareNumber = (long) Math.pow(number, 2);
        long divisor = (long) Math.pow(10, numberDigits(number));
        long leftNumber = squareNumber / divisor;
        long rightNumber = squareNumber % divisor;
        return number == leftNumber + rightNumber;
    }

    private static int numberDigits(long n) {
        return String.valueOf(n).length();
    }
}
