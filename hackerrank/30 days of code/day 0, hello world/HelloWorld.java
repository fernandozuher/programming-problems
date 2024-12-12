// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        System.out.println("Hello, World.");
        System.out.println(input);
    }
}