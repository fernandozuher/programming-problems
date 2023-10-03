// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

import java.io.IOException;
import java.util.Scanner;

public class ExceptionsStringToInteger {
    public static void main(String[] args) throws IOException {

        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();

        try {
            System.out.println(Integer.parseInt(s));
        } catch (NumberFormatException e) {
            System.out.println("Bad String");
        }
    }
}
