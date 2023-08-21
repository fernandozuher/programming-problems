// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

import java.util.Scanner;

public class Loops {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        for (int i = 1, n = scan.nextInt(); i <= 10; i++)
            System.out.format("%d x %d = %d\n", n, i, n * i);
    }
}
