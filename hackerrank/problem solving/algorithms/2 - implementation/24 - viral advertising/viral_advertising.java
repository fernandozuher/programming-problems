// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int days = scan.nextInt();
            System.out.println(viralAdvertising(days));
        }
    }

    private static int viralAdvertising(int days) {
        int cumulative = 0;

        for (int shared = 5; days > 0; days--) {
            int liked = shared / 2;
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
}
