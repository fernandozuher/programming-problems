// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

import java.util.Scanner;

public class DataTypes {

    public static void main(String[] args) {
        final int i = 4;
        final double d = 4.0;
        final String s = "HackerRank ";

        Scanner scan = new Scanner(System.in);
        int i2 = scan.nextInt();
        double d2 = scan.nextDouble();
        scan.nextLine();
        String s2 = scan.nextLine();

        System.out.println(i + i2);
        System.out.println(d + d2);
        System.out.println(s + s2);
    }
}
