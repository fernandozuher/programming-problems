// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int days = scanner.nextInt();
        System.out.println(viralAdvertising(days));
    }

        public static int viralAdvertising(int days) {
            int shared = 5, liked = 0, cumulative = 0;

            while (days-- > 0) {
                liked = shared / 2;
                cumulative += liked;
                shared = liked * 3;
            }

            return cumulative;
        }
}
