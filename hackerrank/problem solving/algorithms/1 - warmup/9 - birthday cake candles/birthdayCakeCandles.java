// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class birthdayCakeCandles {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray();
        System.out.println(birthdayCakeCandles(array));
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).collect(toList());
        }

        private static int birthdayCakeCandles(final List<Integer> candles) {
            int maxElement = Collections.max(candles);
            int count = Collections.frequency(candles, maxElement);
            return count;
        }
}
