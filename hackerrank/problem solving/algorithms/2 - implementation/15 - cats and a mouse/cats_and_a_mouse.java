// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> inputLine = readLineAsListInteger(bufferedReader);
        int n = inputLine.get(0);

        List<List<Integer>> inputLines = readCatsAndMousePositionsLines(bufferedReader, n);

        Result result = new Result(inputLines);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader) {
            try {
                List<Integer> inputLine = Stream.of(bufferedReader.readLine().split(" "))
                                          .map(Integer::parseInt)
                                          .collect(toList());

                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }

        private static List<List<Integer>> readCatsAndMousePositionsLines(BufferedReader bufferedReader, int n) {
            List<List<Integer>> catsAndMousePositionsLines = new ArrayList<List<Integer>>();

            for (int i = 0; i < n; i++)
                catsAndMousePositionsLines.add(readLineAsListInteger(bufferedReader));

            return catsAndMousePositionsLines;
        }
}

    class Result {
        private List<List<Integer>> _catsAndMousePositionsLines;
        private List<String> _result;

        public Result(List<List<Integer>> catsAndMousePositionsLines) {
            _catsAndMousePositionsLines = new ArrayList<List<Integer>>(catsAndMousePositionsLines);
            _result = new ArrayList<String>();

            _catAndMouse();
            printResult();
        }

            private void _catAndMouse() {
                for (List<Integer> catsAndMousePositions : _catsAndMousePositionsLines)
                    _findNearestCatOrNot(catsAndMousePositions);
            }

                private void _findNearestCatOrNot(List<Integer> catsAndMousePositions) {
                    final int catAPosition = catsAndMousePositions.get(0);
                    final int catBPosition = catsAndMousePositions.get(1);
                    final int mousePosition = catsAndMousePositions.get(2);

                    final int catAPositionDifference = Math.abs(catAPosition - mousePosition);
                    final int catBPositionDifference = Math.abs(catBPosition - mousePosition);

                    _setStringResult(catAPositionDifference, catBPositionDifference);
                }

                    private void _setStringResult(int catAPositionDifference, int catBPositionDifference) {
                        if (catAPositionDifference < catBPositionDifference)
                            _result.add("Cat A");
                        else if (catAPositionDifference > catBPositionDifference)
                            _result.add("Cat B");
                        else
                            _result.add("Mouse C");
                    }

            public void printResult() {
                for (String result : _result)
                    System.out.println(result);
            }
    }
