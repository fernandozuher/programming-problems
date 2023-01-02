// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> input1 = readLineAsListInteger(bufferedReader);
        int k = input1.get(1);
        List<Integer> numbers = readLineAsListInteger(bufferedReader);

        Collections.sort(numbers);

        Result result = new Result(numbers, k);
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
        private List<Integer> _numbers;
        private int _k;
        private int _nDivisibleSumPairs;

        public Result(List<Integer> numbers, int k) {
            _numbers = new ArrayList<Integer>(numbers);
            _k = k;
            _nDivisibleSumPairs = 0;

            divisibleSumPairs();
            printResult();
        }

            private void divisibleSumPairs() {
                for (int i = 0, n1 = _numbers.size() - 1; i < n1; i++)
                    for (int j = i + 1; j < _numbers.size(); j++)
                        if (_numbers.get(i) <= _numbers.get(j) && (_numbers.get(i) + _numbers.get(j)) % _k == 0)
                            _nDivisibleSumPairs++;
            }

            public void printResult() {
                System.out.println(_nDivisibleSumPairs);
            }
    }
