// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            int page = scan.nextInt();
            System.out.println(pageCount(n, page));
        }
    }

    private static int pageCount(int n, int page) {
        int fromFront = page / 2;
        int fromBack = n / 2 - fromFront;
        return Math.min(fromFront, fromBack);
    }
}
