// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsListInteger(bufferedReader);

        List<Integer> numbers = readLineAsListInteger(bufferedReader);
        Collections.sort(numbers);

        Result result = new Result(numbers);
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
}

    class Result {
        private List<Integer> _numbers;
        private int _subarrayBiggestSize;

        public Result(List<Integer> numbers) {
            _numbers = new ArrayList<Integer>(numbers);
            _subarrayBiggestSize = 1;

            _pickingNumbers();
            printResult();
        }

            private void _pickingNumbers() {
                int firstReferenceNumberIndex = 0;
                int secondReferenceNumberIndex = 0;
                int subarrayCurrentSize = 1;

                for (int i = 1, n = _numbers.size(); i < n; i++) {
                    final int difference = _numbers.get(i) - _numbers.get(firstReferenceNumberIndex);

                    switch (difference) {
                        case 0:
                            subarrayCurrentSize++;
                            break;

                        case 1:
                            subarrayCurrentSize++;
                            if (_numbers.get(secondReferenceNumberIndex) != _numbers.get(i))
                                secondReferenceNumberIndex = i;
                            break;

                        default:
                            _subarrayBiggestSize = _updateSubarrayBiggestSize(subarrayCurrentSize);

                            final List<Integer> update = _updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                            firstReferenceNumberIndex = update.get(0);
                            secondReferenceNumberIndex = i;
                            subarrayCurrentSize = update.get(1);
                    }
                }

                _subarrayBiggestSize = _updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                int _updateSubarrayBiggestSize(int subarrayCurrentSize) {
                    return Math.max(subarrayCurrentSize, _subarrayBiggestSize);
                }

                List<Integer> _updateFirstReferenceNumberIndexAndSubarrayCurrentSize(int i, int secondReferenceNumberIndex) {
                    int firstReferenceNumberIndex, subarrayCurrentSize;

                    if (_numbers.get(i) - _numbers.get(secondReferenceNumberIndex) == 1) {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    } else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    List<Integer> result = List.of(firstReferenceNumberIndex, subarrayCurrentSize);
                    return result;
                }

            public void printResult() {
                System.out.println(_subarrayBiggestSize);
            }
    }
