// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsListInteger(bufferedReader);
        final String steps = readLineAsString(bufferedReader);

        Result result = new Result(steps);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader) {
            try {
                var inputLine = Stream.of(bufferedReader.readLine().split(" "))
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
                var inputLine = bufferedReader.readLine();
                
                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private String _steps;
        private int _traversedValleys;

        public Result(String steps) {
            _steps = steps;
            _traversedValleys = 0;

            _countingValleys();
            printResult();
        }

            private void _countingValleys() {
                int currentAltitude = 0;

                for (String step : _steps.split("")) {
                    boolean wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step.equals("D") ? -1 : 1;
                    
                    if (_isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        _traversedValleys++;
                }
            }

                private boolean _isInSeaLevelFromValley(boolean wasTravessingAValley, int currentAltitude) {
                    return wasTravessingAValley && currentAltitude == 0;
                }

            public void printResult() {
                System.out.println(_traversedValleys);
            }
    }
