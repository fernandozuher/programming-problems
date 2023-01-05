// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final List<Integer> pageQuantity = readLineAsListInteger(bufferedReader);
        final List<Integer> page = readLineAsListInteger(bufferedReader);

        Result result = new Result(pageQuantity.get(0), page.get(0));
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader)  {
            try {
                var numbers = Stream.of(bufferedReader.readLine().split(" "))
                              .map(Integer::parseInt)
                              .collect(toList());

                return numbers;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private int _pageQuantity;
        private int _page;
        private int _turnOfPagesFromFront;
        private int _turnOfPagesFromBack;
        private int _minimumTurnOfPages;

        public Result(int pageQuantity, int page) {
            _pageQuantity = pageQuantity;
            _page = page;
            _turnOfPagesFromFront = 0;
            _turnOfPagesFromBack = 0;
            _minimumTurnOfPages = 0;

            _drawingBook();
            printResult();
        }

            private void _drawingBook() {
                _turnOfPagesFromFront = _calculateTurnOfPages(_page);
        
                final int maximumTurns = _calculateTurnOfPages(_pageQuantity);

                _turnOfPagesFromBack = maximumTurns - _turnOfPagesFromFront;

                _minimumTurnOfPages = Math.min(_turnOfPagesFromFront, _turnOfPagesFromBack);
            }

                int _calculateTurnOfPages(int page) {
                    return (page & 1) == 1 ? _pageIsOdd(page) : _pageIsEven(page);
                }

                    int _pageIsOdd(int page) {
                        return (page - 1) / 2;
                    }

                    int _pageIsEven(int page) {
                        return page / 2;
                    }

            public void printResult() {
                System.out.println(_minimumTurnOfPages);
            }
}
