// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsListInteger(bufferedReader);
        List<Integer> birdSightings = readLineAsListInteger(bufferedReader);

        Collections.sort(birdSightings);

        Result result = new Result(birdSightings);
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
        private List<Integer> _birdSightings;
        private int _mostSpottedBird;

        public Result(List<Integer> birdSightings) {
            _birdSightings = new ArrayList<Integer>(birdSightings);

            migratoryBirds();
            printResult();
        }

            private void migratoryBirds() {
                _mostSpottedBird = _birdSightings.get(0);
                int count_mostSpottedBird = 1;
                int tempCountMostSpottedBird = 1;

                int n = _birdSightings.size();
                for (int i = 1; i < n; i++)

                    if (_birdSightings.get(i) == _birdSightings.get(i - 1))
                        tempCountMostSpottedBird++;

                    else if (tempCountMostSpottedBird > count_mostSpottedBird) {
                        _mostSpottedBird = _birdSightings.get(i - 1);
                        count_mostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }

                if (tempCountMostSpottedBird > count_mostSpottedBird)
                    _mostSpottedBird = _birdSightings.get(n - 1);
            }

            public void printResult() {
                System.out.println(_mostSpottedBird);
            }
    }
