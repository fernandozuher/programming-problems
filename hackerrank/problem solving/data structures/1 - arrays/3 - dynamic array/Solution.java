// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;
    private static final int querySize = 3;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        int nQueries = scan.nextInt();
        var obj = new DynamicArray(n);

        while (nQueries-- > 0)
            obj.handleQuery(readIntArray(querySize));
        obj.answers().forEach(System.out::println);
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.asList(new Integer[querySize]).stream().map(x -> scan.nextInt()).collect(toList());
        }
}

    class DynamicArray {
        private int n;
        private List<List<Integer>> array;
        private List<Integer> answersToQueries;
        private int lastAnswer;

        public DynamicArray(final int n) {
            this.n = n;

            array = new ArrayList<List<Integer>>(n);
            for (int i = 0; i < n; ++i)
                array.add(new ArrayList<Integer>());

            answersToQueries = new ArrayList<Integer>();
            lastAnswer = 0;
        }

        public void handleQuery(final List<Integer> query) {
            int type = query.get(0);
            int x = query.get(1);
            int y = query.get(2);

            int index = (x ^ lastAnswer) % n;

            if (type == 1)
                array.get(index).add(y);
            else {
                int j = y % array.get(index).size();
                lastAnswer = array.get(index).get(j);
                answersToQueries.add(lastAnswer);
            }
        }

        public List<Integer> answers() {
            return answersToQueries;
        }
    }
