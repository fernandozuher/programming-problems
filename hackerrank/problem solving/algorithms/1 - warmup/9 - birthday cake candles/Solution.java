// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.print(birthdayCakeCandles(n));
    }

        public static int birthdayCakeCandles(int n) {
            int maxCount = 0;
    
            for (int maxElement = 0; n-- > 0; ) {
                int x = scan.nextInt();
                if (x > maxElement) {
                    maxElement = x;
                    maxCount = 1;
                } else if (x == maxElement)
                    ++maxCount;
            }
    
            return maxCount;
        }
}
