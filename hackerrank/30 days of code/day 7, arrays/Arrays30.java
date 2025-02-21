// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true
// From Java 21 onwards

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Arrays30 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        scan.nextLine(); // Ignore not used n
        List<Integer> array = Arrays.stream(scan.nextLine().split(" ")).map(Integer::parseInt).toList();
        for (var x : array.reversed())
            System.out.print(x + " ");
    }
}
