// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class PlusMinus {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine(); // remove new line
        List<Integer> array = readIntArray();
        plusMinus(array);
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).collect(toList());
        }

        private static void plusMinus(List<Integer> array) {
            int positive = 0;
            int negative = 0;
            int zero = 0;

            for (var number : array)
                if (number > 0)
                    ++positive;
                else if (number < 0)
                    ++negative;
                else
                    ++zero;

            int n = array.size();
            double positiveProportion = (double) positive / n;
            double negativeProportion = (double) negative / n;
            double zeroProportion = (double) zero / n;

            System.out.printf("%.6f\n", positiveProportion);
            System.out.printf("%.6f\n", negativeProportion);
            System.out.printf("%.6f\n", zeroProportion);
        }
}
