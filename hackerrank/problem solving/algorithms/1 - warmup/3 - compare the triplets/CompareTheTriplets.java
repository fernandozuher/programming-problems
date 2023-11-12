// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class CompareTheTriplets {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        List<Integer> array1 = readAnIntArray();
        List<Integer> array2 = readAnIntArray();
        List<Integer> result = compareTriplets(array1, array2);
        System.out.println(result.get(0) + " " + result.get(1));
    }

        private static List<Integer> readAnIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }

        private static List<Integer> compareTriplets(List<Integer> array1, List<Integer> array2) {
            int player1 = 0, player2 = 0;

            for (int i = 0; i < array1.size(); ++i) {
                if (array1.get(i) > array2.get(i))
                    player1++;
                else if (array2.get(i) > array1.get(i))
                    player2++;
            }

            return Arrays.asList(player1, player2);
        }
}
