// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class AVeryBigSum {
    public static void main(String[] args)  {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();

        List<Long> array = Stream.of(scan.nextLine().split(" "))
                              .map(Long::parseLong)
                              .collect(toList());
        System.out.println(aVeryBigSum(array));
    }

    private static long aVeryBigSum(final List<Long> array) {
        return array.stream().reduce(0L, (sum, number) -> sum + number);
    }
}
