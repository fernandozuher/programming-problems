// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final int nTestCases = readLineAsInt(bufferedReader);
        final List<Integer> nTestCasesCycles = readCycles(bufferedReader, nTestCases);

        final Result result = new Result(nTestCasesCycles);
    }

        private static int readLineAsInt(BufferedReader bufferedReader) {
            try {
                final int number = Integer.parseInt(bufferedReader.readLine());
                return number;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return 0;
        }

        private static List<Integer> readCycles(BufferedReader bufferedReader, int nTestCases) {

            List<Integer> nTestCasesCycles = IntStream.range(0, nTestCases)
                                             .mapToObj(i -> readLineAsInt(bufferedReader))
                                             .collect(Collectors.toList());
            return nTestCasesCycles;
        }
}

    class Result {
        private List<Integer> _nTestCasesCycles;
        private List<Integer> _treesHeights;

        public Result(List<Integer> nTestCasesCycles) {
            _nTestCasesCycles = new ArrayList<Integer>(nTestCasesCycles);
            _treesHeights = Arrays.asList(new Integer[nTestCasesCycles.size()]);

            _utopianTree();
            printResult();
        }

            private void _utopianTree() {
                for (int i = 0, n = _treesHeights.size(); i < n; i++)
                    _treesHeights.set(i, _calculateHeight(_nTestCasesCycles.get(i)));
            }

                private int _calculateHeight(int cycles) {
                    int height = 1;

                    for (int cycle = 1; cycle <= cycles; cycle++)
                        height = _isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;

                    return height;
                }

                    private boolean _isCycleHappeningDuringSpring(int cycle) {
                        return (cycle & 1) == 1;
                    }

            public void printResult() {
                for (int height : _treesHeights)
                    System.out.println(height);
            }
    }
