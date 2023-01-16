// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final List<Integer> inputLine = readLineAsListInteger(bufferedReader);
        final int maximumHeightCanJump = inputLine.get(1);

        final List<Integer> hurdlesHeights = readLineAsListInteger(bufferedReader);

        final Result result = new Result(hurdlesHeights, maximumHeightCanJump);
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
}

    class Result {
        private List<Integer> _hurdlesHeights;
        private int _maximumHeightCanJump;
        private int _doses;

        public Result(List<Integer> hurdlesHeights, int maximumHeightCanJump) {
            _hurdlesHeights = new ArrayList<Integer>(hurdlesHeights);
            _maximumHeightCanJump = maximumHeightCanJump;
            _doses = 0;

            _hurdleRace();
            printResult();
        }

            private void _hurdleRace() {
                final int highestHurdle = Collections.max(_hurdlesHeights);
                _doses = highestHurdle > _maximumHeightCanJump ? highestHurdle - _maximumHeightCanJump : 0;
            }

            public void printResult() {
                System.out.println(_doses);
            }
    }
