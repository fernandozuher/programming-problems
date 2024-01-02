// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();

        List<Integer> chocolateSquares = readIntArray();
        List<Integer> dayMonth = readIntArray();

        var obj = new TheBirthdayBar(chocolateSquares, dayMonth);
        System.out.println(obj.waysBarCanBeDivided());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class TheBirthdayBar {
        private List<Integer> chocolateSquares;
        private int day, month;
        private int nDivisions;

        public TheBirthdayBar(List<Integer> chocolateSquares, List<Integer> dayMonth) {
            this.chocolateSquares = chocolateSquares;
            day = dayMonth.get(0);
            month = dayMonth.get(1);
            nDivisions = 0;

            birthday();
        }

            private void birthday() {
                for (int i = 0, n1 = chocolateSquares.size() - month + 1; i < n1; ++i) {
                    int sum = 0;

                    for (int j = i, n2 = i + month; j < n2; sum += chocolateSquares.get(j++));
                    if (sum == day)
                        ++nDivisions;
                }
            }

        public int waysBarCanBeDivided() {
            return nDivisions;
        }
    }
