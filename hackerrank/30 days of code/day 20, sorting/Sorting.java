// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Sorting {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String _newLine = scan.nextLine(); // new line character

        List<Integer> list = Stream.of(scan.nextLine().split(" "))
                             .map(Integer::parseInt)
                             .collect(toList());

        System.out.format("Array is sorted in %d swaps.", bubbleSort(list));
        System.out.format("\nFirst Element: %d", list.get(0));
        System.out.format("\nLast Element: %d", list.get(list.size() - 1));
    }

        private static int bubbleSort(List<Integer> a) {
            int numberOfSwaps = 0;

            for (int n = a.size() - 1; n > 0; --n) {
                for (int i = 0; i < n; ++i)
                    if (a.get(i) > a.get(i + 1)) {
                        Collections.swap(a, i, i + 1);
                        ++numberOfSwaps;
                    }

                if (numberOfSwaps == 0)
                    break;
            }

            return numberOfSwaps;
        }
}
