// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final List<Integer> inputLine1 = readLineAsListInteger(bufferedReader);
        final String inputLine2 = readLineAsString(bufferedReader);

        final Result result = new Result(inputLine1, inputLine2);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader) {
            try {
                final var inputLine = Stream.of(bufferedReader.readLine().split(" "))
                                      .map(Integer::parseInt)
                                      .collect(toList());
                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }

        private static String readLineAsString(BufferedReader bufferedReader) {
            try {
                final String inputLine = bufferedReader.readLine();
                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private List<Integer> _lettersHeights;
        private String _word;
        private int _area;

        public Result(List<Integer> lettersHeights, String word) {
            _lettersHeights = new ArrayList<Integer>(lettersHeights);
            _word = word;
            _area = 0;

            _designerPdfViewer();
            printResult();
        }

            private void _designerPdfViewer() {
                int maxHeight = 0;

                for (char letter : _word.toCharArray()) {
                    final int letterIndex = letter - 'a';
                    final int letterHeight = _lettersHeights.get(letterIndex);

                    if (maxHeight < letterHeight)
                        maxHeight = letterHeight;
                }

                _area = maxHeight * _word.length();
            }

            public void printResult() {
                System.out.println(_area);
            }
    }
