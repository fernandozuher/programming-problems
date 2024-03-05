// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;
    private static final int querySize = 3;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        int nQueries = scan.nextInt();

        List<List<Integer>> queries = readQueries(nQueries);
        List<Integer> result = dynamicArray(queries, n);
        result.forEach(System.out::println);
    }

        private static List<List<Integer>> readQueries(int n) {
            var queries = new ArrayList<List<Integer>>(n);
            while (n-- > 0) {
                var query = Arrays.asList(new Integer[querySize]).stream().map(x -> scan.nextInt()).collect(toList());
                queries.add(query);
            }
            return queries;
        }

        private static List<Integer> dynamicArray(final List<List<Integer>> queries, final int n) {
            List<List<Integer>> array = initializeArray(n);
            var answers = new ArrayList<Integer>();
            int lastAnswer = 0;

            for (var query : queries) {
                int type = query.get(0);
                int x = query.get(1);
                int y = query.get(2);

                int index = (x ^ lastAnswer) % n;

                if (type == 1)
                    array.get(index).add(y);
                else {
                    int j = y % array.get(index).size();
                    lastAnswer = array.get(index).get(j);
                    answers.add(lastAnswer);
                }
            }

            return answers;
        }

            private static List<List<Integer>> initializeArray(final int n) {
                var list = new ArrayList<List<Integer>>(n);
                for (int i = 0; i < n; ++i)
                    list.add(new ArrayList<Integer>());
                return list;
            }
}
