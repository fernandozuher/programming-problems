// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.Collections;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class MiniMaxSum {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        List<Integer> array = readIntArray();
        Collections.sort(array);
        miniMaxSum(array);
    }

        private static List<Integer> readIntArray() {
            List<Integer> array = Stream.of(scan.nextLine().split(" "))
                                  .map(Integer::parseInt)
                                  .collect(toList());
            return array;
        }

        private static void miniMaxSum(List<Integer> array) {
            long totalSum = array.stream().mapToLong(Integer::longValue).reduce(0L, (sum, num) -> sum + num);
            long minSum = totalSum - array.get(array.size() - 1);
            long maxSum = totalSum - array.get(0);
            System.out.println(minSum + " " + maxSum);
        }
}
