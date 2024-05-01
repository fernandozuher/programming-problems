// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

import java.util.Scanner;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.stream.IntStream;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int lowerLimit = scan.nextInt();
        int upperLimit = scan.nextInt();
        var validRange = new AtomicBoolean(false);

        IntStream.range(lowerLimit, upperLimit + 1).forEachOrdered(number -> {
            if (isNumberKaprekar(number)) {
                System.out.print(number + " ");
                validRange.set(true);
            }
        });

        if (!validRange.get())
            System.out.println("INVALID RANGE");
    }

        static boolean isNumberKaprekar(int number) {
            long squareNumber = (long)Math.pow(number, 2);
            long divisor = (long)Math.pow(10, numberDigits(number));
            long leftNumber = squareNumber / divisor;
            long rightNumber = squareNumber % divisor;
            return number == leftNumber + rightNumber;
        }
    
            static int numberDigits(long n) {
                if (n < 10) return 1;
                if (n < 100) return 2;
                if (n < 1000) return 3;
                if (n < 10000) return 4;
                if (n < 100000) return 5;
                if (n < 1000000) return 6;
                if (n < 10000000) return 7;
                return 8;
            }
}
