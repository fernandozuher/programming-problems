// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class SimpleArraySum {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();

        List<Integer> array = Stream.of(scan.nextLine().split(" "))
                              .map(Integer::parseInt)
                              .collect(toList());
        System.out.println(simpleArraySum(array));
    }

        private static int simpleArraySum(final List<Integer> array) {
            return array.stream().reduce(0, (sum, num) -> sum + num);
        }
}
