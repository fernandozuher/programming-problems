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
            int positiveQuantity = 0;
            int negativeQuantity = 0;
            int zeroQuantity = 0;

            for (var number : array)
                if (number > 0)
                    ++positiveQuantity;
                else if (number < 0)
                    ++negativeQuantity;
                else
                    ++zeroQuantity;

            int n = array.size();
            double positiveValuesProportion = (double) positiveQuantity / n;
            double negativeValuesProportion = (double) negativeQuantity / n;
            double zeroValuesProportion = (double) zeroQuantity / n;

            System.out.printf("%.6f\n", positiveValuesProportion);
            System.out.printf("%.6f\n", negativeValuesProportion);
            System.out.printf("%.6f\n", zeroValuesProportion);
        }
}
