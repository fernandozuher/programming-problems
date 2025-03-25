// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        try {
            System.out.println(Integer.parseInt(s));
        } catch (NumberFormatException e) {
            System.out.println("Bad String");
        }
    }
}
