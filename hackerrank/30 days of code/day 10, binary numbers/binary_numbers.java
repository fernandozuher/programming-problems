// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        int maxOnes = 0, ones = 0;

        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                ++ones;
            else {
                maxOnes = Math.max(maxOnes, ones);
                ones = 0;
            }
        }

        maxOnes = Math.max(maxOnes, ones);
        System.out.println(maxOnes);
    }
}
